/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:08:50 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/06 15:27:57 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_DEFINE_H
# define SH_DEFINE_H

# define BUFFSIZE 100
# define ERR -1
# define ERR_PARS1_MSG "21sh: syntax error near unexpected token '|'\n"
# define ERR_PARS2_MSG "21sh: syntax error near unexpected token '&'\n"
# define MALLOC_ERR '\00'
# define MALLOC_ERR_MSG "21sh: An error occured while using malloc\n"
# define NO_CHAR_MSG "21sh: Starting without insert character mode\n"
# define NO_NEWLINE_MSG "21sh: Starting without insert line mode\n"
# define NO_DELLINE_MSG "21sh: Starting without del line mode\n"
# define PARSING_ERROR_3 '\04'
# define PARSING_ERROR_3_MSG "21sh: syntax error near unexpected token '<'\n"
# define PARSING_ERROR_4 '\05'
# define PARSING_ERROR_4_MSG "21sh: syntax error near unexpected token '>'\n"
# define PARSING_ERROR_5 '\06'
# define SIGNAL_ERR_MSG "21sh: Failed to setup the catch for signals, exiting"

# define CODE_RESET 0
# define CODE_SET 1
# define CODE_GET 2
# define CODE_PUSH 3

# define BUILTIN "echo\0cd\0setenv\0unsetenv\0env\0exit\0"
# define ESC "\a\b\f\n\r\t\v\\"
# define QUOTES "\"\'"
# define ALL (char *[13]){"||", "&&", "|", "&", ";", ">>", "<<",  "<<", ">&", "<&","<", ">" }
# define HD (char *[14]){"||", "&&", "|", "&", ";", ">>", "<<", ">&", "<&",\
	"<", ">" , " "}
# define SEP (char *[7]){"||", "&&", "|", "&", ";", "\n"}
# define M_SEP (char *[6]){"||", "&&", "|"}
# define REDI (char *[7]){"<<", ">>", "<&",">&", "<", ">"}
# define UNESC "0xabfnrtv\\"

# define BUILT (char *[6]){"echo", "cd", "env", "setenv", "unsetenv"}
# define GLOB "[*?"

# define KEY_LEFT "\33[D"
# define KEY_LEFT_SHITED "\33[1;2D"
# define KEY_RIGHT "\33[C"
# define KEY_RIGHT_SHIFTED "\33[1;2C"
# define KEY_UP "\33[A"
# define KEY_UP_SHITED "\33[1;2A"
# define KEY_DOWN "\33[B"
# define KEY_DOWN_SHITED "\33[1;2B"
# define KEY_SELECT_LEFT "\33\133\61\73\61\60\104"
# define KEY_SELECT_RIGHT "\33\133\61\73\61\60\103"
# define KEY_SELECT_CPY "\75"
# define KEY_SELECT_PASTE "\36\170\146"
# define KEY_END "\33[F"
# define KEY_END_SHIFTED "\33[1;2F"
# define KEY_HOME "\33[H"
# define KEY_HOME_SHIFTED "\33[1;2H"

# define SPECIAL_CHAR (char *[18]){KEY_LEFT, KEY_LEFT_SHITED, KEY_RIGHT, KEY_RIGHT_SHIFTED, KEY_UP, KEY_UP_SHITED, KEY_DOWN, KEY_DOWN_SHITED, KEY_SELECT_LEFT, KEY_SELECT_RIGHT, KEY_SELECT_CPY, KEY_SELECT_CPY, KEY_SELECT_PASTE, KEY_END, KEY_END_SHIFTED, KEY_HOME, KEY_HOME_SHIFTED, 0}
#endif
