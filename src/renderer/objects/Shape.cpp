#include "Shape.h"

float* Geometry::createRectangle(float start_x, float start_y, float end_x, float end_y)
{

        int viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);

        //Data check, if in viewport bound
        if (start_x > viewport[2] || start_y > viewport[3] || start_x < viewport[0] || start_y < viewport[1] || end_x < viewport[0] || end_y < viewport[1] || end_x > viewport[2] || end_y > viewport[3])
        {
            fprintf(stderr, "\nCoordinate out of viewport boundings");
            exit(1);
        }

        int vp_width_half = viewport[2] / 2;
        int vp_height_half = viewport[3] / 2;
        float *rectangle;
        /*         float rectangle[16] = {
            //Coords          TextureCoords
            start_x, start_y, 0.0f, 1.0f,
            start_x, end_y,   0.0f, 0.0f,
            end_x,   end_y,   1.0f, 0.0f,
            end_x,   start_y, 1.0f, 1.0f,
        }; */
        rectangle = new float[15];

        //Load coordinates for drawn rectangle.
        rectangle[0] = start_x;
        rectangle[1] = start_y;
        rectangle[2] = 0.0f;
        rectangle[3] = 1.0f;
        rectangle[4] = start_x;
        rectangle[5] = end_y;
        rectangle[6] = 0.0f;
        rectangle[7] = 0.0f;
        rectangle[8] = end_x;
        rectangle[9] = end_y;
        rectangle[10] = 1.0f;
        rectangle[11] = 0.0f;
        rectangle[12] = end_x;
        rectangle[13] = start_y;
        rectangle[14] = 1.0f;
        rectangle[15] = 1.0f;
        // Update sign.
        for (int i = 0; i < 15; i += 4)
        {
            if (rectangle[i] < vp_width_half)
            {
                rectangle[i] = -viewport[2] + rectangle[i];
            }
            if (rectangle[i + 1] < vp_height_half)
            {
                rectangle[i + 1] = -viewport[3] + rectangle[i + 1];
            }
            if (rectangle[i] == vp_width_half)
            {
                rectangle[i] = -vp_width_half + rectangle[i];
            }
            if (rectangle[i + 1] == vp_height_half)
            {
                rectangle[i + 1] = -vp_height_half + rectangle[i + 1];
            }
        }
        // Normalize the pixels for OpenGL.
        for (int i = 0; i < 15; i += 4)
        {
                rectangle[i] /= viewport[2];
                rectangle[i+1] /= viewport[3];

        }
        SetCount();
        return rectangle;
        delete rectangle;
    }
