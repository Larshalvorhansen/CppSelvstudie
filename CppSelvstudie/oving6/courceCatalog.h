#pragma once
#include "std_lib_facilities.h"

class CourseCatalog{
    private:
        map<string, string> fag{
            {"TMA4101", "Matte1"},
            {"TMA4106", "Matte2"}
        };
    public:
        friend ostream& operator<<(ostream& ostr, const CourseCatalog& cat);
        void addCourse();
        void removeCourse();
        string getCource();
        void toFile();
        void addTree();
        void fromFile();
};
