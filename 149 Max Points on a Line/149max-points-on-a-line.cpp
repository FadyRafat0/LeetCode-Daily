class Solution {
public:
    #define ld long double
    #define point complex<ld>
    #define pi acos(-1)
    #define eps 1e-9

    static ld dot(point a, point b) {
    return (conj(a) * b).real();
    }
    static ld cross(point a, point b) {
    return (conj(a) * b).imag();
    }
    static point scale(point pt, ld factor) {
    return pt * factor;
    }
    // Rotate Around point b an Angle
    static point rotate(point pt, ld angle, point b = {0, 0}) { 
    return (pt - b) * polar((ld)1.0, angle * pi / 180) + b;
    }
    static bool same(point a, point b) {
    return fabs(a.real() - b.real()) < eps && fabs(a.imag() - b.imag()) < eps;
    }
    // Set Length 1 With Same Direction
    static point normalize(point pt) { 
    return {pt.real() / abs(pt), pt.imag() / abs(pt)};
    }
    // Get The Samll Angle Between Them [0, pi] 
    static ld dotAngle(point a, point b, point c) { 
    return acos(dot(b - a, c - a) / (abs(b - a) * abs(c - a)));
    }
    // neg -> C Left of AB , pos -> C Right of AB [-pi, pi]
    static ld crossAngle(point a, point b, point c) {
    return atan2(cross(b - a, c - a), dot(b - a, c - a));
    }
    // 0 -> On Line , Pos -> Left , Neg -> Right
    static ld orient(point a, point b, point c) {
    return cross(b - a, c - a);
    }
    // Angle AntiClockWise Between AB , C [0, 2 * pi]
    static ld orientedAngle(point a, point b, point c) { 
    ld angle = crossAngle(a, b, c);
    if (angle < 0) {
        angle += 2 * pi;
    }
    return angle;
    }
    // Is Point D In Angle ABC
    static bool inAngle(point a, point b, point c, point d) {
    assert(orient(a, b, c) != 0);
    if (orient(a, b, c) < 0) swap(b, c);
    return orient(a, b, d) >= 0 && orient(a, c, d) <= 0;
    } 

    static bool isPerp(point a, point b, point c) { // AB , AC
    return fabs(dotAngle(a, b, c)) < eps;
    }
    static point perp(point a) {
    return {-a.imag(), a.real()};
    }

    // -------------------------- Lines & Segments & Rays -----------------------------

    struct line {
    point v;
    ld c;

    // line from general form Ax + By = C
    line() {}
    line(ld a, ld b, ld cc) {
        v = {b, -a};
        c = cc;
    }
    // line from two points
    line(point a, point b) {
        v = b - a;
        c = cross(v, a);
    }
    // line from direction vector and constant
    line(point v, ld c) : v(v), c(c) {}

    // signed distance of point from the line (positive: left, negative: right)
    ld side(point p) { return cross(v, p) - c; }
    // perpendicular distance from point to the line
    ld dist(point p) { return abs(side(p) / abs(v)); }
    // line perpendicular to current one passing through point p
    line prepThrought(point p) { return {p, p + perp(v)}; }
    // Compare projections of two points on the line direction
    bool cmpProj(point p, point q) { return dot(v, p) < dot(v, q); }
    // Translate line by vector p
    line translate(point p) { return {v, c + cross(v, p)}; }
    // Shift line to the left by a given distance
    line shiftLeft(ld dist) { return {v, c + dist * abs(v)}; }
    // Project point p onto the line
    point projection(point p) { return p - perp(v) * side(p) / abs(v); }
    // Reflect point p across the line
    point reflection(point p) { return p - (perp(v) * (ld)2 * side(p) / abs(v)); }
    };

    // Check if two lines intersect, and store intersection point in `out`
    bool lineIntersect(line l1, line l2, point &out) {
    ld d = cross(l1.v, l2.v);
    if (fabs(d) < eps) {
        // check if they are the same ??
        return false;
    }
    out = (l2.v * l1.c - l1.v * l2.c) / d;
    return true;
    }
    // Return interior or exterior angle bisector between two lines
    line bisector(line l1, line l2, bool interior) {
    assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
    ld sign = interior ? 1 : -1;
    return {l2.v / abs(l2.v) + l1.v / abs(l1.v) * sign,
            l2.c / abs(l2.v) + l1.c / abs(l1.v) * sign};
    }
    bool onLine(line l, point p) {
    return fabs(l.side(p)) < eps;
    }
    // Check if point p lies on the disk (circle segment AB)
    bool inDisk(point a, point b, point p) {
    return dot(a - p, b - p) <= 0;
    }
    // Check if point p lies on segment AB
    bool onSegment(point a, point b, point p) {
    return orient(a, b, p) == 0 && inDisk(a, b, p);
    }
    // Check if two segments intersect, and store intersection point in `out`
    bool segmentIntersect(point a, point b, point c, point d, point &out) {
    ld oa = orient(c, d, a),
        ob = orient(c, d, b),
        oc = orient(a, b, c),
        od = orient(a, b, d);
    if (oa * ob < 0 && oc * od < 0) {
        out = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
    }
    // Return all intersection points between two segments
    set<pair<ld,ld>> segmentInters(point a, point b, point c, point d) {
    set<pair<ld,ld>> s;
    point out;
    if (a == c || a == d) s.insert({a.real(), a.imag()});
    if (b == c || b == d) s.insert({b.real(), b.imag()});
    if (s.size()) return s;

    if (segmentIntersect(a, b, c, d, out)) return {{out.real(), out.imag()}};
    if (onSegment(c, d, a)) s.insert({a.real(), a.imag()});
    if (onSegment(c, d, b)) s.insert({b.real(), b.imag()});
    if (onSegment(a, b, c)) s.insert({c.real(), c.imag()});
    if (onSegment(a, b, d)) s.insert({d.real(), d.imag()});

    return s;
    }
    // distance from point p to segment AB
    ld pointSegDist(point a, point b, point p) {
    if (a != b) {
        line l(a, b);
        if (l.cmpProj(a, p) && l.cmpProj(p, b)) // projection lies between a and b
        return l.dist(p);
    }
    return min(abs(p - a), abs(p - b));
    }
    // distance between two segments AB , CD
    ld segSegDist(point a, point b, point c, point d) {
    point dummy;
    if (segmentIntersect(a, b, c, d, dummy))
        return 0;
    return min({pointSegDist(a, b, c), pointSegDist(a, b, d),
                pointSegDist(c, d, a), pointSegDist(c, d, b)});
    }
    // Check if three points are collinear
    bool isCollinear(point a, point b, point c) {
    return fabs(cross(c - a, b - a)) < eps;
    }
    // Check point c lies on the ray AB
    bool onRay(point a, point b, point c) {
    return same(normalize(b - a), normalize(c - a));
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<point> p(n);
        for (int i = 0; i < n; ++i) {
            ld a = points[i][0], b = points[i][1];
            p[i] = point{a, b};
        }    

        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                line l{p[i], p[j]};
                int cur = 0;
                for (int k = 0; k < n; ++k) {
                    cur += onLine(l, p[k]);
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};