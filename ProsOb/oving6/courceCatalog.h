#pragma once
#include "std_lib_facilities.h"

class CourseCatalog{
    private:
        map<string, string> fag{
            {"TMA4101", "Matte1"},
            {"TMA4106", "Matte2"}
        };
    public:
        void addCourse();
        void removeCourse();
        string getCource();
};
