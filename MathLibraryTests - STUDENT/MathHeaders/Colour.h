#pragma once

namespace MathClasses
{
    struct Colour
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...
        unsigned int colour;

        Colour()
        {
            char red = 0;
            char green = 0;
            char blue = 0;
            char alpha = 255;

            
        }

        Colour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
        {
            SetRed(red);
            SetGreen(green);
            SetBlue(blue);
            SetAlpha(alpha);
        }

        unsigned char GetRed() const
        {
            return colour >> 24;
        }

        unsigned char GetGreen() const
        {
            return colour >> 16;
        }

        unsigned char GetBlue() const
        {
            return colour >> 8;
        }

        unsigned char GetAlpha() const
        {
            return colour;
        }

        void SetRed(unsigned char red)
        {
            unsigned int v = (unsigned int)red << 24;
            colour = colour & 0x00ffffff;
            colour = colour | v;
        }

        void SetGreen(unsigned char green)
        {
            unsigned int v = (unsigned int)green << 16;
            colour = colour & 0xff00ffff;
            colour = colour | v;
        }
        
        void SetBlue(unsigned char blue)
        {
            unsigned int v = (unsigned int)blue << 8;
            colour = colour & 0xffff00ff;
            colour = colour | v;
        }

        void SetAlpha(unsigned char alpha)
        {
            unsigned int v = (unsigned int)alpha << 0;
            colour = colour & 0xffffff00;
            colour = colour | v;
        }

        bool operator==(Colour& other)
        {
            return colour;
        }
    };
}