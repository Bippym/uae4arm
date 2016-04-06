 /*
  * UAE - The Un*x Amiga Emulator
  *
  * Interface to the graphics system (X, SVGAlib)
  *
  * Copyright 1995-1997 Bernd Schmidt
  */

#include "machdep/rpt.h"

typedef uae_u32 xcolnr;

typedef int (*allocfunc_type)(int, int, int, xcolnr *);

extern xcolnr xcolors[4096];

extern int graphics_setup (void);
extern int graphics_init (void);
extern void graphics_leave (void);
extern void handle_events (void);
extern void setup_brkhandler (void);
STATIC_INLINE int isvsync_chipset (void)
{
	if (picasso_on)
		return 0;
	return 1;
}

STATIC_INLINE int isvsync_rtg (void)
{
	if (!picasso_on)
		return 0;
	return 1;
}

extern void flush_screen ();

extern int lockscr (void);
extern void unlockscr (void);

extern void screenshot (int);

extern int bits_in_mask (unsigned long mask);
extern int mask_shift (unsigned long mask);
extern unsigned int doMask (int p, int bits, int shift);
extern unsigned int doMask256 (int p, int bits, int shift);
extern void alloc_colors64k (int, int, int, int, int, int, int);
extern void alloc_colors_picasso (int rw, int gw, int bw, int rs, int gs, int bs, int rgbfmt);

struct vidbuf_description
{
  uae_u8 *bufmem;
  int rowbytes; /* Bytes per row in the memory pointed at by bufmem. */
  int pixbytes; /* Bytes per pixel. */
  int outwidth;
  int outheight;
};

extern struct vidbuf_description gfxvidinfo;

/* For ports using tui.c, this should be built by graphics_setup(). */
extern struct bstring *video_mode_menu;
extern void vidmode_menu_selected(int);