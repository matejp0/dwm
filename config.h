/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 15;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

static const char primary[]         = "#0088A9";
static const char primaryd[]         = "#006882";
static const char secondary[]       = "#A92100";
static const char black[]	    = "#24252A";
static const char white[]	    = "#edf0f1";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { white, black, primaryd },
	[SchemeSel]  = { white, primary,  primary },
};

/* tagging */
static const char *tags[] = { "DEV", "WWW", "SYS", "MED", "COM", "FIL", "MUS", "VID", "VM" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      		instance    title       tags mask     switchtotag    isfloating   monitor */
	{ "NvimCode",  		NULL,       NULL,       1 << 0,       1,             0,           -1 },
	{ "Firefox",  		NULL,       NULL,       1 << 1,       1,             0,           -1 },
	{ "Cadence",     	NULL,       NULL,       1 << 2,       1,             0,           0 },
	{ "Gimp",     		NULL,       NULL,       1 << 3,       1,             0,           -1 },
	{ "Rawtherapee", 	NULL, 			NULL,				1 << 3,				1,						 0,						-1 },
	{ "Darktable", 		NULL, 			NULL,				1 << 3,				1,						 0,						-1 },
	{ "NvimSchool",  	NULL,       NULL,       1 << 3,       1,             0,           -1 },
	{ "thunderbird",  NULL,  			NULL,       1 << 4,       1,             0,           -1 },
	{ "Thunar",   		NULL,       NULL,       1 << 5,       1,             0,           -1 },
	{ "Rhythmbox", 		NULL, 			NULL,				1 << 6,				1,						 0,						-1 },
	{ "Clementine", 	NULL, 			NULL,				1 << 6,				1,						 0,						-1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = {"rofi", "-show", "run", NULL}; 
static char dmenumon[2] = "0";

#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier               key        									function        argument */
	{ MODKEY|ShiftMask,				XK_Return, 									spawn,          { .v = dmenucmd } },
	{ MODKEY,             		XK_Return, 									spawn,          SHCMD("alacritty") },
	{ MODKEY,             		XK_e,	   										spawn,     	   	SHCMD("firefox") },
	{ MODKEY,             		XK_z,	   										spawn,     	   	SHCMD("thunar") },
	{ MODKEY,             		XK_p, 	   									spawn,          SHCMD("pavucontrol") },
	{ MODKEY,             		XK_r, 	   									spawn,          SHCMD("rhythmbox") },
	{ MODKEY,             		XK_c, 	   									spawn,          SHCMD("clementine") },
	{ MODKEY,             		XK_t, 	   									spawn,          SHCMD("rawtherapee") },
	{ MODKEY,             		XK_g, 	   									spawn,          SHCMD("gimp") },
	{ MODKEY,             		XK_m, 	   									spawn,          SHCMD("thunderbird") },


	{ MODKEY,             		XK_o, 	   									spawn,          SHCMD("alacritty -e 'echo $PATH && sleep 5000'") },


	{ MODKEY,             		XK_s, 	   									spawn,          SHCMD("/usr/local/bin/slock") },
	{ 0,											XF86XK_AudioLowerVolume,		spawn, 					SHCMD("/usr/bin/pactl set-sink-volume 0 -5%") },
	{ 0,                      XF86XK_AudioRaiseVolume, 		spawn, 					SHCMD("/usr/bin/pactl set-sink-volume 0 +5%") },
	{ 0,                      XF86XK_AudioMute,						spawn,					SHCMD("/usr/bin/pactl set-sink-mute 0 toggle") },
	{ 0,             					XF86XK_AudioMicMute, 				spawn, 					SHCMD("cadence") },
	{ 0,											XF86XK_MonBrightnessUp,			spawn,					SHCMD("/usr/bin/light -A 5") },
	{ 0,											XF86XK_MonBrightnessDown, 	spawn, 					SHCMD("/usr/bin/light -U 5") },
	{ 0, 											XF86XK_Launch1, 						spawn, 					SHCMD("systemctl suspend") },

	{ MODKEY,                 XK_b,      									togglebar,      {0} },
	{ MODKEY,             		XK_a,      									rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,       XK_j,      									rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,       XK_k,      									rotatestack,    {.i = -1 } },
	{ MODKEY,                 XK_j,      									focusstack,     {.i = +1 } },
	{ MODKEY,                 XK_k,      									focusstack,     {.i = -1 } },
	{ MODKEY,                 XK_i,      									incnmaster,     {.i = +1 } },
	{ MODKEY,                 XK_d,      									incnmaster,     {.i = -1 } },
	{ MODKEY,                 XK_h,      									setmfact,       {.f = -0.05} },
	{ MODKEY,                 XK_l,      									setmfact,       {.f = +0.05} },
	{ MODKEY,                 XK_w, 											zoom,           {0} },
	{ MODKEY,                 XK_Tab,    									view,           {0} },
	{ MODKEY,            			XK_q,      									killclient,     {0} },
	{ MODKEY|ShiftMask,       XK_space,  									togglefloating, {0} },
	{ MODKEY,             		XK_f,      									togglefullscr,  {0} },
	{ MODKEY,                 XK_0,      									view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,       XK_0,      									tag,            {.ui = ~0 } },
	{ MODKEY,                 XK_comma,  									focusmon,       {.i = -1 } },
	{ MODKEY,                 XK_period, 									focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,       XK_comma,  									tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,       XK_period, 									tagmon,         {.i = +1 } },
	{ MODKEY,                 XK_minus,  									setgaps,        {.i = -1 } },
	{ MODKEY,                 XK_equal,  									setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,      	XK_equal,  									setgaps,        {.i = 0  } },
	{ MODKEY|ShiftMask,       XK_q,      									quit,           {0} },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          SHCMD("alacritty") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

