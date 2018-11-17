#include <string>

struct Specialization {
    string specialization;

    explicit Specialization(string new_specialization) {
        specialization = new_specialization;
    }
};

struct Course {
    string course;

    explicit Course(string new_course) {
        course = new_course;
    }
};

struct Week {
    string week;

    explicit Week(string new_week) {
        week = new_week;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization s, Course c, Week w) {
        specialization = s.specialization;
        course = c.course;
        week = w.week;
    }
};
