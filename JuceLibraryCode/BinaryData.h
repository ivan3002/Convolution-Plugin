/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   testimagethree_jpg;
    const int            testimagethree_jpgSize = 385489;

    extern const char*   testimagetwo_jpeg;
    const int            testimagetwo_jpegSize = 416062;

    extern const char*   stereoIR_Genelecs_Better_Vol_stereo_wav;
    const int            stereoIR_Genelecs_Better_Vol_stereo_wavSize = 1440044;

    extern const char*   stereoIR_Phone_Speaker_stereo_wav;
    const int            stereoIR_Phone_Speaker_stereo_wavSize = 1440044;

    extern const char*   stereoIR_Portable_Speaker_stereo_wav;
    const int            stereoIR_Portable_Speaker_stereo_wavSize = 864044;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 5;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
