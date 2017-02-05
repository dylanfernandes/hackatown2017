/******************************************************************************/
/*
* File name: MAppStart.cpp 
*
* Synopsis:  This program allocates a MIL application and system, then displays 
*            a welcoming message using graphics functions. It also shows how 
*            to check for errors.
*/
#include <mil.h>
#include <iostream>
#include <fstream>
#include <string>

#define IMAGE_X 500
#define IMAGE_Y 333

using namespace std;

float ExtractCoordinate(string line)
{
	string strCoordinate = line.substr(3);
	return(stof(strCoordinate));
}
int main(int argc, char *argv[])
{
	MIL_ID MilApplication,  /* Application identifier.  */
		MilSystem,       /* System identifier.       */
		MilDisplay,      /* Display identifier.      */
		MilImage;        /* Image buffer identifier. */

	/* Allocate a default MIL application, system, display and image. */
	MappAllocDefault(M_DEFAULT, &MilApplication, &MilSystem, 
		&MilDisplay, M_NULL, &MilImage);

	MIL_TEXT_CHAR INFILE[256];
	MOs_strcpy(INFILE, argv[1]);
	MIL_ID MilImage2;
	MbufRestore(INFILE, MilSystem, &MilImage2);
	MdispSelect(MilDisplay, MilImage2);
	//parse coordinate
	string line;
	ifstream myfile (argv[2]);
	float x1=0, x2=0, x3, x1_end=0, x2_end=0, x3_end=0, y1=0, y2=0, y3=0,y1_end=0, y2_end=0, y3_end=0;
	if (myfile.is_open())
	{
		while ( getline (myfile,line)) 
		{
			float ratio_x1 = ExtractCoordinate(line);
			x1 = ratio_x1 * IMAGE_X;
			getline (myfile,line);

			float ratio_y1 = ExtractCoordinate(line);
			x1 = ratio_y1 * IMAGE_Y;
			getline (myfile,line);

			float ratio_x1_end = ExtractCoordinate(line);
			x1_end = ratio_x1_end * IMAGE_X;
			getline (myfile,line);

			float ratio_y1_end = ExtractCoordinate(line);
			y1_end = ratio_y1_end * IMAGE_X;
			getline (myfile,line);

			float ratio_x2 = ExtractCoordinate(line);
			x2 = ratio_x2 * IMAGE_Y;
			getline (myfile,line);

			float ratio_y2 = ExtractCoordinate(line);
			y2 = ratio_y2 * IMAGE_X;
			getline (myfile,line);

			float ratio_x2_end = ExtractCoordinate(line);
			x2_end = ratio_x2_end * IMAGE_Y;
			getline (myfile,line);

			float ratio_y2_end = ExtractCoordinate(line);
			y2_end = ratio_y2_end * IMAGE_X;
			getline (myfile,line);

			float ratio_x3 = ExtractCoordinate(line);
			x3 = ratio_x3 * IMAGE_Y;
			getline (myfile,line);


			float ratio_y3 = ExtractCoordinate(line);
			y3 = ratio_y3 * IMAGE_X;
			getline (myfile,line);

			float ratio_x3_end = ExtractCoordinate(line);
			x3_end = ratio_x3_end * IMAGE_Y;
			getline (myfile,line);

			float ratio_y3_end = ExtractCoordinate(line);
			y3_end = ratio_y3_end * IMAGE_X;
			getline (myfile,line);

		}
		myfile.close();
	}

    MgraRect(M_DEFAULT, MilImage2, x1, x1_end, y1, y1_end);
	MgraRect(M_DEFAULT, MilImage2, x2, x2_end, y2, y2_end);
	MgraRect(M_DEFAULT, MilImage2, x3, x3_end, y3, y3_end);

	MOs_strcat(INFILE, MIL_TEXT("_"));
	MbufSave(INFILE, MilImage2);

	getchar();
	MbufFree(MilImage2);
	/* Free defaults. */
	MappFreeDefault(MilApplication, MilSystem, MilDisplay, M_NULL, MilImage);

	return 0;
}

