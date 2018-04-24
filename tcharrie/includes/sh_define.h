/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:54:38 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/24 10:47:05 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_DEFINE_H
# define SH_DEFINE_H
# define NO_CHAR_MSG "21sh: Starting without insert character mode\n"
# define NO_NEWLINE_MSG "21sh: Starting without insert line mode\n"
# define NO_DELLINE_MSG "21sh: Starting without del line mode\n"
# define SIGNAL_ERR_MSG "21sh: Failed to setup the catch for signals, exiting"
# define MALLOC_ERR '\00'
# define MALLOC_ERR_MSG "21sh: An error occured while using malloc\n"
# define PARSING_ERROR_3 '\04'
# define PARSING_ERROR_3_MSG "21sh: syntax error near unexpected token '<'\n"
# define PARSING_ERROR_4 '\05'
# define PARSING_ERROR_4_MSG "21sh: syntax error near unexpected token '>'\n"
# define PARSING_ERROR_5 '\06'
# define ERR_PARS1_MSG "21sh: syntax error near unexpected token '|'\n"
# define ERR_PARS2_MSG "21sh: syntax error near unexpected token '&'\n"

# define CODE_RESET 0
# define CODE_SET 1
# define CODE_GET 2
# define CODE_PUSH 3

# define ERR -1
#endif
