#John Parkhurst
#Dependencies: MESA, FreeGlut, G++


#Linux
g++ -Wall main.cpp gl_frontEnd.cpp imageIO_TGA.cpp rasterImage.cpp -lm -lGL -lglut -o focus
./focus
#Mac
#g++ main.cpp gl_frontEnd.cpp imageIO_TGA.cpp -lm -framework OpenGL -framework GLUT -o focus
echo "End"
