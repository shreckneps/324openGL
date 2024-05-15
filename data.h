//data.h, Spencer Butler, CS324 OpenGL, 11/16/2023

#ifndef data_h
#define data_h

//constants for f1 type information
#define SB_POINTS (1 << 0)
#define SB_LINES (0)

//constants for f2 type information
#define SB_QUADS (1 << 1)
#define SB_TRIS (0)
#define SB_WIREFRAME (1 << 0)
#define SB_SOLID (0)

//Draws name and class information
void writeName();

//Draws the 2D function according to type
//SB_POINTS/SB_LINES
void f1(int type);

//Draws the 3D function according to type
//SB_QUADS/SB_TRIS and SB_WIREFRAME/SB_SOLID
void f2(int type);

//Draws all four configurations of the 3D function
void f2_all();

//Draws a rubik's cube with gaps of input-specified width
void rubik(double gaps);

//Draws a grid of rubik's cubes with gaps
void rubik_grid();

//Wrapper for f1(SB_POINTS)
void f1_points();

//Wrapper for f1(SB_LINES)
void f1_lines();

//Wrapper for f2(SB_QUADS | SB_WIREFRAME)
void f2_qw();

//Wrapper for f2(SB_QUADS | SB_SOLID)
void f2_qs();

//Wrapper for f2(SB_TRIS | SB_WIREFRAME)
void f2_tw();

//Wrapper for f2(SB_TRIS | SB_SOLID)
void f2_ts();

//Wrapper for rubik(0.0)
void rubik_solid();

//Wrapper for rubik(0.05)
void rubik_gaps();


#endif
