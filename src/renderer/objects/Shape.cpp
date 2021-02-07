#include "Shape.h"

float* Geometry::createObject(float start_x, float start_y, float end_x, float end_y)
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
        float *raw_data;
        raw_data = new float[15];

        //Load coordinates for drawn rectangle.
        raw_data[0] = start_x;
        raw_data[1] = start_y;
        raw_data[2] = 0.0f;
        raw_data[3] = 1.0f;
        raw_data[4] = start_x;
        raw_data[5] = end_y;
        raw_data[6] = 0.0f;
        raw_data[7] = 0.0f;
        raw_data[8] = end_x;
        raw_data[9] = end_y;
        raw_data[10] = 1.0f;
        raw_data[11] = 0.0f;
        raw_data[12] = end_x;
        raw_data[13] = start_y;
        raw_data[14] = 1.0f;
        raw_data[15] = 1.0f;
        // Update sign.
        for (int i = 0; i < 15; i += 4)
        {
            if (raw_data[i] < vp_width_half)
            {
                raw_data[i] = -viewport[2] + raw_data[i];
            }
            if (raw_data[i + 1] < vp_height_half)
            {
                raw_data[i + 1] = -viewport[3] + raw_data[i + 1];
            }
            if (raw_data[i] == vp_width_half)
            {
                raw_data[i] = -vp_width_half + raw_data[i];
            }
            if (raw_data[i + 1] == vp_height_half)
            {
                raw_data[i + 1] = -vp_height_half + raw_data[i + 1];
            }
        }
        // Normalize the pixels for OpenGL.
        for (int i = 0; i < 15; i += 4)
        {
                raw_data[i] /= viewport[2];
                raw_data[i+1] /= viewport[3];

        }
        SetCount();
        return raw_data;
        delete raw_data;
    }
