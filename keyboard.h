/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:10:06 by thvocans          #+#    #+#             */
/*   Updated: 2017/10/07 17:01:35 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H
/*
** ESC - Fkeys row
*/
# define K_ESC			(w->key.down[6]) & (1 << 5)
# define K_F1			(w->key.down[15]) & (1 << 2)
# define K_F2			(w->key.down[15]) & (1 << 0)
# define K_F3			(w->key.down[12]) & (1 << 3)
# define K_F4			(w->key.down[14]) & (1 << 6)
# define K_F5			(w->key.down[12]) & (1 << 0)
# define K_F6			(w->key.down[12]) & (1 << 1)
# define K_F7			(w->key.down[12]) & (1 << 2)
# define K_F8			(w->key.down[12]) & (1 << 4)
# define K_F9			(w->key.down[12]) & (1 << 5)
# define K_F10			(w->key.down[13]) & (1 << 5)
# define K_F12			(w->key.down[13]) & (1 << 7)
# define K_F13			(w->key.down[13]) & (1 << 1)
# define K_F14			(w->key.down[13]) & (1 << 3)
# define K_F15			(w->key.down[14]) & (1 << 1)
# define K_F16			(w->key.down[13]) & (1 << 2)
# define K_F17			(w->key.down[8]) & (1 << 0)
# define K_F18			(w->key.down[9]) & (1 << 7)
# define K_F19			(w->key.down[10]) & (1 << 0)
/*
** Tilde row
*/
# define K_TILDE		(w->key.down[6]) & (1 << 2)
# define K_1			(w->key.down[2]) & (1 << 2)
# define K_2			(w->key.down[2]) & (1 << 3)
# define K_3			(w->key.down[2]) & (1 << 4)
# define K_4			(w->key.down[2]) & (1 << 5)
# define K_5			(w->key.down[2]) & (1 << 7)
# define K_6			(w->key.down[2]) & (1 << 6)
# define K_7			(w->key.down[3]) & (1 << 2)
# define K_8			(w->key.down[3]) & (1 << 4)
# define K_9			(w->key.down[3]) & (1 << 1)
# define K_0			(w->key.down[3]) & (1 << 5)
# define K_DASH			(w->key.down[3]) & (1 << 3)
# define K_EQUAL		(w->key.down[3]) & (1 << 0)
# define K_BACKSPACE	(w->key.down[6]) & (1 << 3)
/*
** TAB row
*/
# define K_TAB			(w->key.down[6]) & (1 << 0)
# define K_Q			(w->key.down[1]) & (1 << 4)
# define K_W			(w->key.down[1]) & (1 << 5)
# define K_E			(w->key.down[1]) & (1 << 6)
# define K_R			(w->key.down[1]) & (1 << 7)
# define K_T			(w->key.down[2]) & (1 << 1)
# define K_Y			(w->key.down[2]) & (1 << 0)
# define K_U			(w->key.down[4]) & (1 << 0)
# define K_I			(w->key.down[4]) & (1 << 2)
# define K_O			(w->key.down[3]) & (1 << 7)
# define K_P			(w->key.down[4]) & (1 << 3)
# define K_OP_BRACK		(w->key.down[4]) & (1 << 1)
# define K_CL_BRACK		(w->key.down[3]) & (1 << 6)
# define K_BACKSLASH	(w->key.down[5]) & (1 << 2)
/*
** CAPS LOCK row
*/
# define K_CAPS			(w->key.down[34]) & (1 << 0)
# define K_A			(w->key.down[0]) & (1 << 0)
# define K_S			(w->key.down[0]) & (1 << 1)
# define K_D			(w->key.down[0]) & (1 << 2)
# define K_F			(w->key.down[0]) & (1 << 3)
# define K_G			(w->key.down[0]) & (1 << 5)
# define K_H			(w->key.down[0]) & (1 << 4)
# define K_J			(w->key.down[4]) & (1 << 6)
# define K_K			(w->key.down[5]) & (1 << 0)
# define K_L			(w->key.down[4]) & (1 << 5)
# define K_SEMICOL		(w->key.down[5]) & (1 << 1)
# define K_QUOTE		(w->key.down[4]) & (1 << 7)
# define K_RETURN		(w->key.down[4]) & (1 << 4)
/*
** Shift row
*/
# define K_L_SHIFT		(w->key.down[32]) & (1 << 1)
# define K_Z			(w->key.down[0]) & (1 << 6)
# define K_X			(w->key.down[0]) & (1 << 7)
# define K_C			(w->key.down[1]) & (1 << 0)
# define K_V			(w->key.down[1]) & (1 << 1)
# define K_B			(w->key.down[1]) & (1 << 3)
# define K_N			(w->key.down[5]) & (1 << 5)
# define K_M			(w->key.down[5]) & (1 << 6)
# define K_COMMA		(w->key.down[5]) & (1 << 3)
# define K_DOT			(w->key.down[5]) & (1 << 7)
# define K_SLASH		(w->key.down[5]) & (1 << 4)
# define K_R_SHIFT		(w->key.down[32]) & (1 << 2)
# define K_SHIFT ((w->key.down[32]) & (1 << 2) || (w->key.down[32]) & (1 << 1))
/*
** Ctrl row
*/
# define K_L_CTRL		(w->key.down[32]) & (1 << 0)
# define K_L_ALT		(w->key.down[32]) & (1 << 5)
# define K_L_CMD		(w->key.down[32]) & (1 << 3)
# define K_SPACE		(w->key.down[6]) & (1 << 1)
# define K_R_CMD		(w->key.down[32]) & (1 << 4)
# define K_R_ALT		(w->key.down[32]) & (1 << 6)
# define K_R_CTRL		(w->key.down[33]) & (1 << 5)
/*
** Arrow block
*/
# define K_LEFT			(w->key.down[15]) & (1 << 3)
# define K_RIGHT		(w->key.down[15]) & (1 << 4)
# define K_UP			(w->key.down[15]) & (1 << 6)
# define K_DOWN			(w->key.down[15]) & (1 << 5)
# define K_FN			(w->key.down[34]) & (1 << 7)
# define K_DEL			(w->key.down[14]) & (1 << 5)
# define K_HOME			(w->key.down[14]) & (1 << 3)
# define K_END			(w->key.down[14]) & (1 << 7)
# define K_PAGEUP		(w->key.down[14]) & (1 << 4)
# define K_PAGEDOWN		(w->key.down[15]) & (1 << 1)
/*
** NUMPAD block
*/
# define NUM_0			(w->key.down[10]) & (1 << 2)
# define NUM_1			(w->key.down[10]) & (1 << 3)
# define NUM_2			(w->key.down[10]) & (1 << 4)
# define NUM_3			(w->key.down[10]) & (1 << 5)
# define NUM_4			(w->key.down[10]) & (1 << 6)
# define NUM_5			(w->key.down[10]) & (1 << 7)
# define NUM_6			(w->key.down[11]) & (1 << 0)
# define NUM_7			(w->key.down[11]) & (1 << 1)
# define NUM_8			(w->key.down[11]) & (1 << 3)
# define NUM_9			(w->key.down[11]) & (1 << 4)
# define NUM_CLR		(w->key.down[8]) & (1 << 7)
# define NUM_EQUAL		(w->key.down[10]) & (1 << 1)
# define NUM_DIV		(w->key.down[9]) & (1 << 3)
# define NUM_MULT		(w->key.down[8]) & (1 << 3)
# define NUM_MINUS		(w->key.down[9]) & (1 << 6)
# define NUM_PLUS		(w->key.down[8]) & (1 << 5)
# define NUM_ENTER		(w->key.down[9]) & (1 << 4)
# define NUM_DOT		(w->key.down[8]) & (1 << 1)
#endif
