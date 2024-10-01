/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:07:57 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 01:19:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char* retrievePaths(char** envp)
{

    int i = 0;
    while(envp[i] != NULL)
    {
        if(ft_strncmp(envp[i], "PATH=", 5) == 0)
            return (envp[i] + 5);
        i++;
    }
    ft_putstr_fd("File not found\n", 2);
    return (NULL);
}

void abs_path(char *cmd, char** envp)
{
    char **argv;
    
    argv = malloc(sizeof(char*) * 2);
    argv[1] = NULL;
    argv[0] = cmd;
    if(access(cmd, X_OK) == 0)
        execve(cmd, argv, envp);
    else
        ft_putstr_fd("No such file or directory\n", 2);
}
int cmd_exec(char **split_paths, char **envp, char **av)
{
    int i;
    int cmd_found;
    char* path_joined;
    char* search_program;
    cmd_found = 0;
    i = -1;
    
    while(split_paths[i++] != NULL)
    {
        path_joined = ft_strjoin(split_paths[i], "/");    
        search_program = ft_strjoin(path_joined, av[0]);
        if(access(search_program, X_OK) == 0)
        {
            cmd_found = 1;
            execve(search_program, &av[0], envp);
            break;
        }
        free(path_joined);
        free(search_program);
    }
    return (cmd_found);
}
int envp_split(char* cmd, char** envp)
{
    int cmd_found;
    cmd_found = 0;
    
    if(cmd[0] == '/')
        abs_path(cmd, envp);
    else
    {
        char** av = ft_split(cmd, ' '); //ls -l or // /bin/ls
        char* all_paths = retrievePaths(envp);
        char** split_paths = ft_split(all_paths, ':');
        cmd_found = cmd_exec(split_paths, envp, av);
        if(!cmd_found)
            return (1);
    }
    return (0);
}

//execve = {"/bin/ls", ("ls", "-l", NULL), envp};
//execve = {"/bin/ls", (NULL), envp};
        //if the command is not found, print an error message

//handling /dev/urandom
//error output handling
          //  ft_putstr_fd("Error: command not found\n", 1);
