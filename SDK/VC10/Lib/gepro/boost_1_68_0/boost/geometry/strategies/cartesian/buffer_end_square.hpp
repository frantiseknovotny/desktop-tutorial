// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2012-2014 Barend Gehrels, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_STRATEGIES_CARTESIAN_BUFFER_END_SQUARE_HPP
#define BOOST_GEOMETRY_STRATEGIES_CARTESIAN_BUFFER_END_SQUARE_HPP

#include <boost/geometry/core/cs.hpp>
#include <boost/geometry/strategies/tags.hpp>
#include <boost/geometry/strategies/side.hpp>
#include <boost/geometry/util/math.hpp>
#include <boost/geometry/util/select_most_precise.hpp>

#include <boost/geometry/strategies/buffer.hpp>



namespace boost { namespace geometry
{


namespace strategy { namespace buffer
{


/*!
\brief Let the buffer create square ends
\ingroup strategies
\details This strategy can be used as EndStrategy for the buffer algorithm.
    It creates a square end for each linestring-end. It can be applied
    for (multi)linestrings. Also it is applicable for spikes in (multi)polygons.
    This strategy is only applicable for Cartesian coordinate systems.

 */
  /// \to do zatim to z nejakeho duvodu nefunguje, ale zustava to tu aby se dal pouzit ten zpusob zakonceni
  /// pouziva se to v geom_utils_zl.cpp ve funkci lin_buffer_ex, ale obejde se to prodlouzenim linie a pouzitim end_flat
class end_square
{


    template <typename T, typename P1, typename P2>
    static inline T calculate_angle(P1 const& from_point, P2 const& to_point)
    {
        typedef P1 vector_type;
        vector_type v = from_point;
        geometry::subtract_point(v, to_point);
        return atan2(geometry::get<1>(v), geometry::get<0>(v));
    }

public :

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    //! Fills output_range with a flat end
    template <typename Point, typename RangeOut, typename DistanceStrategy>
    inline void apply(Point const& penultimate_point,
                Point const& perp_left_point,
                Point const& ultimate_point,
                Point const& perp_right_point,
                buffer_side_selector side,
                DistanceStrategy const& distance,
                RangeOut& range_out) const
    {
        typedef typename coordinate_type<Point>::type coordinate_type;

        typedef typename geometry::select_most_precise
        <
            coordinate_type,
            double
        >::type promoted_type;

        promoted_type const half_pi = geometry::math::half_pi<promoted_type>();


        promoted_type const dist_left = distance.apply(penultimate_point, ultimate_point, buffer_side_left);
        promoted_type const dist_right = distance.apply(penultimate_point, ultimate_point, buffer_side_right);

        bool reversed = (side == buffer_side_left && dist_right < 0 && -dist_right > dist_left)
                    || (side == buffer_side_right && dist_left < 0 && -dist_left > dist_right)
                    ;
        if (reversed)
        {
           promoted_type const alpha_left = calculate_angle<promoted_type>(perp_left_point, ultimate_point) - half_pi;
           promoted_type const alpha_right = calculate_angle<promoted_type>(perp_right_point, ultimate_point) + half_pi;

           typename boost::range_value<RangeOut>::type p;
           set<0>(p, get<0>(perp_right_point) + dist_right * cos(alpha_left) + 10.);
           set<1>(p, get<1>(perp_right_point) + dist_right * sin(alpha_left));
           range_out.push_back(p);

           set<0>(p, 0.);
           set<1>(p, 0.);
           range_out.push_back(p);


           set<0>(p, get<0>(perp_left_point) + dist_left * cos(alpha_right));
           set<1>(p, get<1>(perp_left_point) + dist_left * sin(alpha_right) + 10.);
           range_out.push_back(p);

           // range_out.push_back(perp_right_point);
           // range_out.push_back(perp_left_point);
        }
        else
        {
           promoted_type const alpha_left = calculate_angle<promoted_type>(perp_left_point, ultimate_point) - half_pi;
           promoted_type const alpha_right = calculate_angle<promoted_type>(perp_right_point, ultimate_point) + half_pi;

           typename boost::range_value<RangeOut>::type p;
           set<0>(p, get<0>(perp_left_point) + dist_left * cos(alpha_left) + 10.);
           set<1>(p, get<1>(perp_left_point) + dist_left * sin(alpha_left));
           range_out.push_back(p);

           set<0>(p, get<0>(perp_right_point) + dist_right * cos(alpha_right));
           set<1>(p, get<1>(perp_right_point) + dist_right * sin(alpha_right) + 10.);
           range_out.push_back(p);

           // range_out.push_back(perp_left_point);
           // range_out.push_back(perp_right_point);
        }
        // Don't add the ultimate_point (endpoint of the linestring).
        // The buffer might be generated completely at one side.
        // In other cases it does no harm but is further useless
    }

    template <typename NumericType>
    static inline NumericType max_distance(NumericType const& distance)
    {
        return distance;
    }

    //! Returns the piece_type (flat end)
    static inline piece_type get_piece_type()
    {
        return buffered_round_end;
    }
#endif // DOXYGEN_SHOULD_SKIP_THIS
};


}} // namespace strategy::buffer

}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_STRATEGIES_CARTESIAN_BUFFER_END_FLAT_HPP
