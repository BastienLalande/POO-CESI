#include <iostream>
#include <cmath>

typedef enum {
    POINT,
    COLINEAR_INTERSECTING,
    COLINEAR_NON_INTERSECTING,
    PARALLEL_NON_INTERSECTING,
    NON_INTERSECTING
} IntersectionStatus;

class Vector2 {
    public:
    double x;
    double y;
    void init(double _x, double _y) {
        this->x = _x;
        this->y = _y;
    }
    double norm() {
        return sqrt(this->x * this->x + this->y * this->y);
    }
    void negate() {
        this->x = -this->x;
        this->y = -this->y;
    }
};

double dot(Vector2 v, Vector2 r) {
    return v.x * r.x + v.y * r.y;
}

double det_vector(Vector2 v, Vector2 r) {
    return v.x * r.y - v.y * r.x;
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
    void init(double _x, double _y) {
        this->x = _x;
        this->y = _y;
    }
    
};

Point2 Point2_add(Point2 p,Vector2 r) {
    Point2 result;
    result.x = p.x + r.x;
    result.y = p.y + r.y;
    return result;
}

Vector2 Point2_sub(Point2 p, Point2 r) {
    Vector2 result;
    result.x = p.x - r.x;
    result.y = p.y - r.y;
    return result;
}

class Segment2 {
    public:
    Point2 origin;
    Vector2 direction;
    void init(Point2 _origin, Vector2 _direction) {
        this->origin = _origin;
        this->direction = _direction;
    }
    double length() {
        return direction.norm();
    }
};

IntersectionStatus Segment2_intersect(Segment2 s,Segment2 r, Point2 *p) {
    Point2 oa = s.origin, ob = r.origin;
    Vector2 da = s.direction, db = r.direction;
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
            d2 = d1 + dot(db, da) / pj;

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
    std::cout << "debut du programme" << std::endl;
    Point2 p1, p2;
    p1.init(0., 0.);
    p2.init(1., 0.);
    Vector2 v1, v2;
    v1.init(4., 4.);
    v2.init(-4., 4.);
    Segment2 s1, s2;
    s1.init(p1, v1);
    s2.init(p2, v2);

    
    Point2 p3;
    IntersectionStatus status = Segment2_intersect(s1, s2, &p3);
    std::cout << "status: " << status << std::endl;
    std::cout << "p3:(" << p3.x << "," << p3.y << ")" << std::endl;

    return EXIT_SUCCESS;
}