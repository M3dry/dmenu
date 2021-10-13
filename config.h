/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int instant = 0;
static int topbar = 1;                     /* -b  option; if 0, dmenu appears at bottom */
static int centered = 0;                   /* -c option; centers dmenu on screen */
static int fuzzy = 0;                      /* -F  option; if 0, dmenu doesn't use fuzzy matching */
static int colorprompt = 1;                /* -p  option; if 1, prompt uses SchemeSel, otherwise SchemeNorm */
static int min_width = 500;                /* minimum width when centered */
static int opacity = 0;                    /* -o  option; if 0, then alpha is disabled */
static const char *fonts[] = {
    "Operator Mono SSm Lig:pixelsize=16:antialias=true:autohint=true",
    "joypixels:pixelsize=14:antialias=true:autohint=true"
};

static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
    /*                        fg         bg       */
    [SchemeNorm] =          { "#eeffff", "#0f111b" },
    [SchemeSel] =           { "#000000", "#ff5370" },
    [SchemeOut] =           { "#000000", "#000000" },
    [SchemeMid] =           { "#eeffff", "#1e1c31" },
    [SchemeSelHighlight] =  { "#ff5370", "#000000" },
    [SchemeNormHighlight] = { "#ff5370", "#0f111b" },
};

static const unsigned int baralpha = OPAQUE;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
	/*                        fg      bg        border     */
	[SchemeNorm]          = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]           = { OPAQUE, baralpha, borderalpha },
	[SchemeOut]           = { OPAQUE, baralpha, borderalpha },
	[SchemeMid]           = { OPAQUE, baralpha, borderalpha },
	[SchemeSelHighlight]  = { OPAQUE, baralpha, borderalpha },
	[SchemeNormHighlight] = { OPAQUE, baralpha, borderalpha },
};

/* -l and -g options; controls number of lines and columns in grid if > 0 */
static unsigned int lines      = 0;
static unsigned int columns    = 0;

/* -h option; minimum height of a menu line */
static unsigned int lineheight = 0;
static unsigned int min_lineheight = 8;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 0;
