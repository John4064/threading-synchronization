#John Parkhurst
#Dependencies: MESA, FreeGlut, G++
#Linux
echo "start"
#g++ -Wall main.cpp gl_frontEnd.cpp imageIO_TGA.cpp -lm -lGL -lglut -o focus
#Mac
g++ main.cpp gl_frontEnd.cpp imageIO_TGA.cpp rasterImage.cpp -L/System/Library/Frameworks -lm -framework OpenGL -framework GLUT -o focus
./focus
echo "End"
