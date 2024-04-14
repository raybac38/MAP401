#include "ps.h"
#include <stdio.h>
#include <string.h>
// #include <stdlib.h>


void WriteStroke(FILE *f);
void WriteStrokeColor(FILE *f, char r, char g, char b) ;
void WriteStrokeWidth(FILE *f, unsigned epaisseur) ;
void WriteEntete(FILE *f, Point2 dimention);
void WriteFooter(FILE *f);
void CloseFile(FILE *f);
void WriteFill(FILE *f);
void WriteMoveto(FILE *f, Point2 a);
void WriteLineto(FILE *f, Point2 a);
void WriteCurveto3(FILE *f, Point2 a, Point2 b, Point2 c);
FILE *OpenFile(char *name);



void PsSimpleSegment(Tableau * contours, Point2 dimention, char * name)
{
    FILE * f = OpenFile(name);
    WriteEntete(f, dimention);

    for (size_t i = 0; i < TableauGetSize(contours); i++)
    {
        Tableau *tab = TableauGetTableau(contours, i);

        WriteMoveto(f, TableauGetPoint2(tab, 0));

        for (size_t j = 1; j < TableauGetSize(tab); j++)
        {
            WriteLineto(f, TableauGetPoint2(tab, j));
        }
        WriteStrokeWidth(f,0);
        WriteStrokeColor(f, 255, 0, 0);
    }

    WriteFill(f);

    WriteFooter(f);

    CloseFile(f);
}
void WriteFooter(FILE *f)
{
    fprintf(f, "showpage\n");
}

void CloseFile(FILE *f)
{
    fclose(f);
}

void WriteFill(FILE *f)
{
    fprintf(f, "fill\n");
}

void WriteStroke(FILE *f)
{
    fprintf(f, "stroke\n");
}

void WriteMoveto(FILE *f, Point2 a)
{
    fprintf(f,"%f %f moveto\n", GetValuePoint2(a, 'x'), GetValuePoint2(a, 'y'));
}

void WriteLineto(FILE *f, Point2 a)
{
    fprintf(f, "%f %f lineto\n", GetValuePoint2(a, 'x'), GetValuePoint2(a, 'y'));
}

void WriteCurveto3(FILE *f, Point2 a, Point2 b, Point2 c)
{
    fprintf(f, "%f %f %f %f %f %f curveto\n",
            GetValuePoint2(a, 'x'), GetValuePoint2(a, 'y'),
            GetValuePoint2(b, 'x'), GetValuePoint2(b, 'y'),
            GetValuePoint2(c, 'x'), GetValuePoint2(c, 'y'));
}

FILE * OpenFile(char *name)
{
    strcat(name, ".eps");
    FILE * f = fopen(name, "w");
    return f;
}

void WriteEntete(FILE *f, Point2 dimention)
{
    fprintf(f, "%%!PS-Adobe-3.0 EPSF-3.0\n");
    fprintf(f, "%%%%BoundingBox: 0 0 %d %d\n", (unsigned)GetValuePoint2(dimention, 'x'), (unsigned)GetValuePoint2(dimention, 'y'));
}

void WriteStrokeColor(FILE *f, char r, char g, char b) 
{
    fprintf(f, "%d %d %d setrgbcolor\n", r / 255, g / 255, b / 255);
}
void WriteStrokeWidth(FILE *f, unsigned epaisseur) 
{
    fprintf(f, "%d setlinewidth\n", epaisseur);
}



//__________________________________________________________________________
void PsCourbeBezier(Tableau * contours, Point2 dimention, char * name)
{
    FILE * f = OpenFile(name);
    WriteEntete(f, dimention);

    for (size_t i = 0; i < TableauGetSize(contours); i++)
    {
        Tableau *tab = TableauGetTableau(contours, i);

        WriteMoveto(f, TableauGetPoint2(tab, 0));

        for (size_t j = 1; j < TableauGetSize(tab); j++)
        {
            if ((j % 3) == 0) {
                WriteCurveto3(f, TableauGetPoint2(tab, j-2), TableauGetPoint2(tab,j-1), TableauGetPoint2(tab,j));
            }

        }
        WriteStrokeWidth(f,0);
        WriteStrokeColor(f, 255, 0, 0);
    }

    WriteFill(f);

    WriteFooter(f);

    CloseFile(f);
}
//___________________________________________________________________



