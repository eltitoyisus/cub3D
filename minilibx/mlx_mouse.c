#include "mlx_int.h"

int mlx_mouse_move(t_xvar *xvar, t_win_list *win, int x, int y)
{
    XWarpPointer(xvar->display, None, win->window, 0, 0, 0, 0, x, y);
    return (0);
}

int mlx_mouse_hide(t_xvar *xvar, t_win_list *win)
{
    static char data[1] = {0};  // Keeps a static blank pixmap for the cursor
    static Cursor cursor = None;  // To track if the cursor has been created
    Pixmap blank;
    XColor dummy;

    // If a cursor has already been created, free it
    if (cursor != None)
    {
        XFreeCursor(xvar->display, cursor);  // Free the previous cursor if it exists
    }

    // Create a blank pixmap
    blank = XCreateBitmapFromData(xvar->display, win->window, data, 1, 1);

    // Create a new blank cursor
    cursor = XCreatePixmapCursor(xvar->display, blank, blank, &dummy, &dummy, 0, 0);

    // Hide the cursor by defining the blank cursor
    XDefineCursor(xvar->display, win->window, cursor);

    // Free the blank pixmap after use
    XFreePixmap(xvar->display, blank);

    return (0);
}

int mlx_mouse_show(t_xvar *xvar, t_win_list *win)
{
    // Show the cursor again by undefining it
    XUndefineCursor(xvar->display, win->window);
    return (0);
}

/*
** Queries the position of the mouse pointer relative to the origin of the
** specified window and saves it to the provided location.
**
** If the pointer is not on the same screen as the specified window, both
** win_x_return and win_y_return are set to zero and the function returns 0.
*/

int mlx_mouse_get_pos(t_xvar *xvar, t_win_list *win, \
        int *win_x_return, int *win_y_return)
{
    Window root_return;
    Window child_return;
    int root_x_return;
    int root_y_return;
    unsigned mask_return;

    return (XQueryPointer(xvar->display, win->window, \
        &root_return, &child_return, &root_x_return, &root_y_return, \
        win_x_return, win_y_return, &mask_return));
}

/*
** Cleanup function to properly close the display and release any resources
** that have been allocated.
*/
void mlx_cleanup(t_xvar *xvar)
{
    // Close the X display connection to ensure resources are freed
    if (xvar->display)
    {
        XCloseDisplay(xvar->display);
    }
}
