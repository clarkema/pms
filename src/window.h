/* vi:set ts=8 sts=8 sw=8:
 *
 * Practical Music Search
 * Copyright (c) 2006-2011  Kim Tore Jensen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _PMS_WINDOW_H_
#define _PMS_WINDOW_H_

#include "curses.h"
#include "songlist.h"
#include <vector>

using namespace std;

#define WWINDOW(x)	dynamic_cast<Window *>(x)
#define WCONSOLE(x)	dynamic_cast<Wconsole *>(x)
#define WMAIN(x)	dynamic_cast<Wmain *>(x)

class Window
{
	protected:
		Rect *		rect;

	public:
		void		set_rect(Rect * r) { rect = r; };

		/* Window height */
		unsigned int	height();

		/* Draw all lines on rect */
		void		draw();

		/* Clear this window */
		void		clear();

		/* Is this window visible? */
		virtual bool	visible() { return true; };

		/* Draw one line on rect */
		virtual void	drawline(int y) = 0;

};

class Wmain : public Window
{
	protected:

	public:

		/* Scroll position */
		unsigned int	position;

		/* Cursor position */
		unsigned int	cursor;


		Wmain();

		/* Scroll window */
		virtual void	scroll_window(int offset);

		/* Move cursor inside window */
		virtual void	move_cursor(int offset);

		/* Set absolute window/cursor position */
		virtual void	set_position(unsigned int absolute);
		virtual void	set_cursor(unsigned int absolute);

		/* List size */
		virtual unsigned int content_size() = 0;

		/* Is this window visible? */
		bool		visible();
};

class Wconsole : public Wmain
{
	public:
		void		drawline(int rely);
		unsigned int	content_size();
		void		move_cursor(int offset);
		void		set_cursor(unsigned int absolute);
};

class Wsonglist : public Wmain
{
	public:
		void		drawline(int rely);
		unsigned int	content_size();

		/* Pointer to connected songlist */
		Songlist *	songlist;
};

class Wtopbar : public Window
{
	public:
		void		drawline(int rely) {};
};

class Wstatusbar : public Window
{
	public:
		void		drawline(int rely);
};

class Wreadout : public Window
{
	public:
		void		drawline(int rely);
};

class Windowmanager
{
	private:
		vector<Window *>	windows;

		/* Active window index */
		unsigned int		active_index;
	
	public:
		Windowmanager();

		/* What kind of input events are accepted right now */
		int			context;

		/* Redraw all visible windows */
		void			draw();

		/* Cycle window list */
		void			cycle(int offset);

		/* Activate a window */
		bool			activate(Window * nactive);

		Wconsole *		console;
		Wsonglist *		playlist;
		Wsonglist *		library;

		Window *		active;
		Wtopbar *		topbar;
		Wstatusbar *		statusbar;
		Wreadout *		readout;
};

#endif /* _PMS_WINDOW_H_ */