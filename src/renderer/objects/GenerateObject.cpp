#include "GenerateObject.h"

float* Geometry::createRectangle(float start_x, float start_y, float end_x, float end_y){


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
        float *raw_buffer_data;
        raw_buffer_data = new float[7];

        //Load coordinates for drawn rectangle.
        raw_buffer_data[0] = start_x;
        raw_buffer_data[1] = start_y;
        raw_buffer_data[2] = start_x;
        raw_buffer_data[3] = end_y;
        raw_buffer_data[4] = end_x;
        raw_buffer_data[5] = end_y;
        raw_buffer_data[6] = end_x;
        raw_buffer_data[7] = start_y;

        // Update sign.
        for (int i = 0; i < 8; i += 2)
        {
            if (raw_buffer_data[i] < vp_width_half)
            {
                raw_buffer_data[i] = -viewport[2] + raw_buffer_data[i];
            }
            if (raw_buffer_data[i + 1] < vp_height_half)
            {
                raw_buffer_data[i + 1] = -viewport[3] + raw_buffer_data[i + 1];
            }
            if (raw_buffer_data[i] == vp_width_half)
            {
                raw_buffer_data[i] = -vp_width_half + raw_buffer_data[i];
            }
            if (raw_buffer_data[i + 1] == vp_height_half)
            {
                raw_buffer_data[i + 1] = -vp_height_half + raw_buffer_data[i + 1];
            }
        }
        // Convert the pixels values to percentage for OpenGL
        for (int i = 0; i < 8; i++)
        {
            if (i % 2 == 0 || i == 0)
            {
                raw_buffer_data[i] /= viewport[2];
            }
            else
            {
                raw_buffer_data[i] /= viewport[3];
            }
        }

        return raw_buffer_data;
        delete raw_buffer_data;
    }