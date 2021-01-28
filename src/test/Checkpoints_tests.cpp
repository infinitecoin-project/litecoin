//
// Unit tests for block-chain checkpoints
//
#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>

#include "../checkpoints.h"
#include "../util.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p1500 = uint256("0x605a02ce718ced87b68a3e601081358c64091dc6e546f0e444cafe6e8f73cef5");
    uint256 p120000 = uint256("0x00a7bdd2d47ba640fe8d1ef18638a8d7c77f179a0ed23e51fc83a71da2005b45");
    BOOST_CHECK(Checkpoints::CheckBlock(1500, p1500));
    BOOST_CHECK(Checkpoints::CheckBlock(120000, p120000));

    
    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(1500, p120000));
    BOOST_CHECK(!Checkpoints::CheckBlock(120000, p1500));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(1500+1, p120000));
    BOOST_CHECK(Checkpoints::CheckBlock(120000+1, p1500));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 120000);
}    

BOOST_AUTO_TEST_SUITE_END()
