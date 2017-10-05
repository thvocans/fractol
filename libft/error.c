/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:59:32 by thvocans          #+#    #+#             */
/*   Updated: 2017/10/05 01:15:44 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_no_args(void)
{
	ft_putstr_fd("             ▄▄▄█▀▀▀▀▀▀▄▄▄        \n", 2);
	ft_putstr_fd("         ▄█▀▀           ▀▀█▄▄     \n", 2);
	ft_putstr_fd("       ▄█▀      ▄▄▄        ▄▀█▄   \n", 2);
	ft_putstr_fd("       █          ▀▀▄    ▄▀▀   █▄ \n", 2);
	ft_putstr_fd("      █         ▄█▀▀▀█▄ ▄█▀▀▀█▄ ▀▄\n", 2);
	ft_putstr_fd("     █          ██ O ██ ██ O ██  █\n", 2);
	ft_putstr_fd("     █          ▀█████▀ ▀█████▀  █\n", 2);
	ft_putstr_fd("     █                ▄    █     █\n", 2);
	ft_putstr_fd("     █                ██▀▀▀▀█    █\n", 2);
	ft_putstr_fd("     █               █ ▄▀▄▄▄▀    █   Dude really ?\n", 2);
	ft_putstr_fd("     █               _-----_     █\n", 2);
	ft_putstr_fd("     █▄             |-_-_-_-|    █", 2);
	ft_putstr_fd(" Y U NO ARGUMENTS !!??\n", 2);
	ft_putstr_fd("      █▄             -_____-    ▄▀\n", 2);
	ft_putstr_fd("      ▄█▄                     ▄█▀ \n", 2);
	ft_putstr_fd("    ▄█▀▄  ▀▄▄  ▄▄       ---▄▄▀▀   \n", 2);
	ft_putstr_fd("  ▄█▀   ▀▄   ▀▀▀██▄▄▄▄▄▄█▀▀    ▄▄ \n", 2);
	ft_putstr_fd("▄▀        █       ▄█▀▄ ▄▄▄    ▀██▀\n", 2);
	ft_putstr_fd("▀          █▄    ▄█▄▄▄█████▄▄▄▀▀  \n", 2);
	ft_putstr_fd("             ▀▀▀█▀▀▀▀▀ ▀██▀       \n", 2);
	ft_putstr_fd("               ▄▀                 \n", 2);
}

static void	ft_too_much_args(void)
{
	ft_putstr_fd("         ▄              ▄    \n", 2);
	ft_putstr_fd("        ▌ █           ▄▀ ▌   \n", 2);
	ft_putstr_fd("        ▌  ▀▄       ▄▀   ▐   \n", 2);
	ft_putstr_fd("       ▐▄▀  ▀▀▀▀▄▄▄▀     ▐   \n", 2);
	ft_putstr_fd("     ▄▄▀           █  ▄█ ▐       SUCH ARGS\n", 2);
	ft_putstr_fd("   ▄▀               ▀██▀ ▌   \n", 2);
	ft_putstr_fd("  ▐   ▄▄▄             ▀▄  ▌", 2);
	ft_putstr_fd("                         MUCH CHARS\n", 2);
	ft_putstr_fd("  ▌  ▐▄█▀    ▄▀█▄       █ ▐  \n", 2);
	ft_putstr_fd(" ▐           ▌██▀        ▀▄▌             WOW\n", 2);
	ft_putstr_fd(" ▌ ▀▄██▄           ░░░░    ▌ \n", 2);
	ft_putstr_fd(" ▌▀▐▄█▄█▌▄ ▀      ░░░░░░   ▐                    WOW\n", 2);
	ft_putstr_fd("▐ ▀▐▀▐▀  ▄▄ ▄     ░░░░░░    ▌\n", 2);
	ft_putstr_fd("▐   ▀▀▄▄   ▄      ░░░░░░   ▐ \n", 2);
	ft_putstr_fd(" ▌      ▀▀▀        ░░░░    ▌ \n", 2);
	ft_putstr_fd(" ▐                        ▐            PUT LESS ARGS\n", 2);
	ft_putstr_fd("  ▀▄                 ▄    ▌  \n", 2);
	ft_putstr_fd("    ▀▄          ▄▄▄▀    ▄▀          MUCH BETTER\n", 2);
	ft_putstr_fd("   ▐▀ ▀▄▄▄▄▄▄▀▀▀     ▄▄▀     \n", 2);
	ft_putstr_fd("  ▐                ▀▀          ", 2);
	ft_putstr_fd("                       WOW\n", 2);
}

static void	ft_no_mem(void)
{
	ft_putstr_fd("        ▄▄▄███                    \n", 2);
	ft_putstr_fd("   ▄▄██████████                   \n", 2);
	ft_putstr_fd(" ███████████████                  \n", 2);
	ft_putstr_fd(" ▀███████████████     ▄▄▄         \n", 2);
	ft_putstr_fd("   ███████████████▄███▀▀▀         \n", 2);
	ft_putstr_fd("    ███████████████▄▄                 ", 2);
	ft_putstr_fd("I am truly sorry my dearest friend\n", 2);
	ft_putstr_fd("    ▄████████▀▀▄▄▄▄▄ ▀               ", 2);
	ft_putstr_fd("nonetheless i sincerely hope our lack\n", 2);
	ft_putstr_fd("▄███████▀█ ▀█▄  █ ▀▀▀ █  ▄▄             ", 2);
	ft_putstr_fd("of memory will not influence our\n", 2);
	ft_putstr_fd("▀▀   ██▄█    █  ▄███████▄█▀  ▄               ", 2);
	ft_putstr_fd("friendly relationship\n", 2);
	ft_putstr_fd("     █ █▀▄▄ ▄▀ █▀▀▀█▀▄▄▀      ▄  █\n", 2);
	ft_putstr_fd("     █ █  ▀▀▄▄█▀ █▀▀  █       ▀██                 ", 2);
	ft_putstr_fd("deepest regards,\n", 2);
	ft_putstr_fd("     ▀█▄             ▄▀      ▄██                      ", 2);
	ft_putstr_fd("   Louis 1er de Malloc\n", 2);
	ft_putstr_fd("      ▀█▄▄        ▄▄█      ▄▀  █  \n", 2);
	ft_putstr_fd("         ▀███▀▀████▄██▄▄  ▄▀      \n", 2);
	ft_putstr_fd("           █▄▀██▀██▀▄█▄ ▀▀        \n", 2);
	ft_putstr_fd("           ██ ▀█▄█ █▀ ▀▄          \n", 2);
	ft_putstr_fd("          █ █▄  ▀█▄▄▄  █          \n", 2);
	ft_putstr_fd("          █▀██▀▀▀▀ █▄             \n", 2);
	ft_putstr_fd("            ▀           ▀         \n", 2);
}

static void	ft_invalid_file(void)
{
	ft_putstr_fd("          ▄▄▄█▀▀▀▀▀▀▀▄▄         Invalid file\n", 2);
	ft_putstr_fd("       ▄█▀  ▄█▄        ██▄     \n", 2);
	ft_putstr_fd("     ▄▀       ▀       ▀▀▀ ▀▄   \n", 2);
	ft_putstr_fd("   ▄▀   ▄▀█████▄       ▄▀▀▄▄█  \n", 2);
	ft_putstr_fd(" ▄█    █▀▀     ▀      ▀█▀▀▀▀██ \n", 2);
	ft_putstr_fd(" █                      ▀    █▄    I see\n", 2);
	ft_putstr_fd("█            ▄▀  ▄▄▄▄▄▄▀▄     █\n", 2);
	ft_putstr_fd("█           █▄▄████▄█████     █     what\n", 2);
	ft_putstr_fd("█             ▀▀████████▀     █\n", 2);
	ft_putstr_fd("█▄                ▀▀▀▀▀       █   you did\n", 2);
	ft_putstr_fd(" █▄                          █▀\n", 2);
	ft_putstr_fd("  ▀█▄                       ▄▀     there.\n", 2);
	ft_putstr_fd("    ▀▀▄▄                  ▄█▀  \n", 2);
	ft_putstr_fd("       ▀▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀▀     \n", 2);
}

void		ft_error(int error)
{
	if (error == 0)
		ft_no_args();
	if (error == 1)
		ft_too_much_args();
	if (error == 2)
		ft_no_mem();
	if (error == 3)
		ft_wrong_fd();
	if (error == 4)
		ft_invalid_file();
	exit(1);
}
