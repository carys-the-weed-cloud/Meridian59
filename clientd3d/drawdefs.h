// Meridian 59, Copyright 1994-2012 Andrew Kirmse and Chris Kirmse.
// All rights reserved.
//
// This software is distributed under a license that is described in
// the LICENSE file that accompanies it.
//
// Meridian is a registered trademark.
/*
 * drawdefs.h:  Basic constants for 3D drawing, defining sizes and resolutions.
 *   This file is included by draw3d.h.
 */

#ifndef DRAWDEFS_H
#define DRAWDEFS_H

#define NUMDEGREES 4096
#define LOG_NUMDEGREES 12
#define NUMDEGREES_MASK 0xfff

#define PI      3.141592653589793238
#define PITWICE 6.283185307179586476
#define PIHALF  1.57079632679

/* Turning MACROs */
#define TURN_LEFT(angle) ((angle + 3 * NUMDEGREES / 4) % NUMDEGREES)
#define TURN_RIGHT(angle) ((angle + NUMDEGREES / 4) % NUMDEGREES)
#define TURN_BACK(angle) ((angle + NUMDEGREES / 2) % NUMDEGREES)

/* Max viewport size -- must be DWORD aligned for WinG */
#define MAXX 452
#define MAXY 276

/* Fineness of offset within a grid square. */
#define FINENESS     1024       /* Keep track of rays to within 1/FINENESS */
#define LOG_FINENESS 10         /* Discrete log of FINENESS */
#define FINE_MASK    0xfffffc00

/* Convert from fineness to (square, offset) and vice versa */
#define FineToSquare(x) ((x) >> LOG_FINENESS)
#define FineToOffset(x) ((x) & ~FINE_MASK)
#define SquareToFine(s, o) ((s) << LOG_FINENESS | (o))

/* Convert from kod (square, fineness) to client fineness */
#define KOD_FINENESS     64           // Kod has 64 units per grid square
#define LOG_KOD_FINENESS 6
#define SquareToFineKod(s, o) ((s) << LOG_FINENESS | ((o) << (LOG_FINENESS - LOG_KOD_FINENESS)))
#define FinenessKodToClient(f) ((f) << (LOG_FINENESS - LOG_KOD_FINENESS))
#define FinenessClientToKod(f) ((f) >> (LOG_FINENESS - LOG_KOD_FINENESS))

// Convert from room file/kod height to fineness height
#define HeightKodToClient(f) ((f) << (LOG_FINENESS - LOG_KOD_FINENESS))

#define VIEWER_DISTANCE  (FINENESS >> 1)         /* Distance from viewer to screen in pixels */
#define LOG_VIEWER_DISTANCE  (LOG_FINENESS - 1)

/* Convert from pseudo degrees to radians */
#define DegToRad(x) ((x) * PITWICE / NUMDEGREES)
#define RadToDeg(x) ((x) * NUMDEGREES / PITWICE)

#define NUM_COLORS 256
#define MAX_LIGHT 256  
#define LIGHT_LEVELS 64
#define KOD_LIGHT_LEVELS 256

/* Palette constants */
#define NUM_PALETTES (LIGHT_LEVELS + 1)
#define PALETTE_INVERT LIGHT_LEVELS    // Index of inverted (nuclear-effect) palette

#endif /* #ifdef _DRAWDEFS_H */
