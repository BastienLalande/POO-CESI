#include <iostream>
#include <cmath>

using IntersectionStatus = enum : std::uint8_t {
    POINT,
    COLINEAR_INTERSECTING,
    COLINEAR_NON_INTERSECTING,
    PARALLEL_NON_INTERSECTING,
    NON_INTERSECTING
};

class Vector2 {
    public:
    double x;
    double y;
    Vector2() : x(0.0), y(0.0) {}
    Vector2(double _x, double _y) : x(_x), y(_y) {}
    double norm() const {
        return sqrt((this->x * this->x) + (this->y * this->y));
    }
    void negate() {
        this->x = -this->x;
        this->y = -this->y;
    }
};

double dot(Vector2 v, Vector2 r) {
    return (v.x * r.x) + (v.y * r.y);
}

double det_vector(Vector2 v, Vector2 r) {
    return (v.x * r.y) - (v.y * r.x);
}

Vector2 dot_scalar(Vector2 v, double u) {
    v.x = u * v.x;
    v.y = u * v.y;
    return v;
}

class Point2 {
    public:
    double x;
    double y;
    Point2() : x(0.0), y(0.0) {}
    Point2(double _x, double _y) : x(_x), y(_y) {}

};

Point2 Point2_add(Point2 p,Vector2 r) {
    Point2 result(p.x + r.x, p.y + r.y);
    return result;
}

Vector2 Point2_sub(Point2 p, Point2 r) {
    Vector2 result(p.x - r.x, p.y - r.y);
    return result;
}

class Segment2 {
    public:
    Point2 origin;
    Vector2 direction;
    Segment2(Point2 _origin, Vector2 _direction) : origin(_origin), direction(_direction) {}
    double length() const {
        return direction.norm();
    }
};

IntersectionStatus Segment2_intersect(Segment2 s,Segment2 r, Point2 *p) {
    Point2 oa = s.origin;
    Point2 ob = r.origin;
    Vector2 da = s.direction;
    Vector2 db = r.direction;
    Vector2 dc = Point2_sub(ob, oa);

    IntersectionStatus status;
    double det = det_vector(da, db);
    if (det != 0.0) {
        double u, v;

        u = det_vector(dc, db) / det;
        v = det_vector(dc, da) / det;
        if ((u >= 0.0 && u <= 1.0) && (v >= 0.0 && v <= 1.0)) {
            Vector2 tmp = dot_scalar(da, u);
            *p = Point2_add(oa, tmp);
            status = POINT;
        } else {
            status = NON_INTERSECTING;
        }
    } else {
        double st = det_vector(dc, da);
        if (det == 0.0 && st == 0.0) { // check for collinearity
            double pj, d1, d2;

            pj = dot(da, da);
            d1 = dot(dc, da) / pj;
            d2 = d1 + (dot(db, da) / pj);

            if (d1 >= 0.0 && d1 <= 1.0) {
                *p = ob;
                status = COLINEAR_INTERSECTING;
            } else if (d2 >= 0.0 && d2 <= 1.0) {
                Point2 tmp_ob_db = Point2_add(ob, db);
                *p = tmp_ob_db;
                status = COLINEAR_INTERSECTING;
            } else {
                status = COLINEAR_NON_INTERSECTING;
            }
        } else if (det == 0.0 && st != 0.0) {
            status = PARALLEL_NON_INTERSECTING;
        }
    }
    return status;
}

int main() {
    std::cout << "debut du programme" << '\n';
    Point2 p1(0., 0.);
    Point2 p2(1., 0.);
    Vector2 v1(4., 4.);
    Vector2 v2(-4., 4.);
    Segment2 s1(p1, v1);
    Segment2 s2(p2, v2);


    Point2 p3;
    IntersectionStatus status = Segment2_intersect(s1, s2, &p3);
    std::cout << "status: " << status << '\n';
    std::cout << "p3:(" << p3.x << "," << p3.y << ")" << '\n';

    return EXIT_SUCCESS;
}
