#John Parkhurst
#Dependencies: MESA, FreeGlut, G++

g++ -Wall main.cpp gl frontEnd.cpp fileIO TGA.cpp -lm -lGL -lglut -o focus

echo "Complete"