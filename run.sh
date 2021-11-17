#John Parkhurst
#Dependencies: MESA  FreeGlut  G++
#Linux
echo  start
#g++ -Wall main.cpp gl_frontEnd.cpp imageIO_TGA.cpp -lm -lGL -lglut -o focus
#Mac
g++ main.cpp gl_frontEnd.cpp imageIO_TGA.cpp rasterImage.cpp -L/System/Library/Frameworks -lm -framework OpenGL -framework GLUT -o focus
./focus 12  ./output/inFocus.tga ./images/_MG_6291.tga ./images/_MG_6293.tga ./images/_MG_6294.tga ./images/_MG_6295.tga ./images/_MG_6296.tga ./images/_MG_6297.tga ./images/_MG_6298.tga ./images/_MG_6299.tga ./images/_MG_6300.tga ./images/_MG_6301.tga ./images/_MG_6302.tga
echo  End
