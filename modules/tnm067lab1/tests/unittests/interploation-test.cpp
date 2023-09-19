#include <warn/push>
#include <warn/ignore/all>
#include <gtest/gtest.h>
#include <warn/pop>

#include <initializer_list>
#include <array>
#include <modules/tnm067lab1/utils/interpolationmethods.h>
#include <array>

namespace inviwo {

namespace ip = TNM067::Interpolation;

#if ENABLE_LINEAR_UNITTEST == 1
TEST(InterpolationTests, SimpleLinearTest) {

    EXPECT_FLOAT_EQ(0.314f, ip::linear(0.f, 1.f, 0.314f));

    for (const auto& f : {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0}) {
        EXPECT_FLOAT_EQ(f, ip::linear(0.f, 1.f, f));
    }
}
TEST(InterpolationTests, LinearUInt8Test) {
    std::uint8_t a = 0;
    std::uint8_t b = 255;
    EXPECT_EQ(207, ip::linear<std::uint8_t>(a, b, 0.81472367048263549805));
    EXPECT_EQ(34, ip::linear<std::uint8_t>(a, b, 0.13547700643539428711));
    EXPECT_EQ(230, ip::linear<std::uint8_t>(a, b, 0.90579193830490112305));
    EXPECT_EQ(212, ip::linear<std::uint8_t>(a, b, 0.83500856161117553711));
    EXPECT_EQ(32, ip::linear<std::uint8_t>(a, b, 0.12698681652545928955));
    EXPECT_EQ(247, ip::linear<std::uint8_t>(a, b, 0.96886777877807617188));
    EXPECT_EQ(232, ip::linear<std::uint8_t>(a, b, 0.9133758544921875));
    EXPECT_EQ(56, ip::linear<std::uint8_t>(a, b, 0.22103404998779296875));
    EXPECT_EQ(161, ip::linear<std::uint8_t>(a, b, 0.63235926628112792969));
    EXPECT_EQ(78, ip::linear<std::uint8_t>(a, b, 0.30816704034805297852));
    EXPECT_EQ(24, ip::linear<std::uint8_t>(a, b, 0.097540400922298431396));
    EXPECT_EQ(139, ip::linear<std::uint8_t>(a, b, 0.54722058773040771484));
    EXPECT_EQ(71, ip::linear<std::uint8_t>(a, b, 0.27849823236465454102));
    EXPECT_EQ(48, ip::linear<std::uint8_t>(a, b, 0.18838196992874145508));
    EXPECT_EQ(139, ip::linear<std::uint8_t>(a, b, 0.54688149690628051758));
    EXPECT_EQ(253, ip::linear<std::uint8_t>(a, b, 0.99288129806518554688));
    EXPECT_EQ(244, ip::linear<std::uint8_t>(a, b, 0.9575068354606628418));
    EXPECT_EQ(254, ip::linear<std::uint8_t>(a, b, 0.99646133184432983398));
    EXPECT_EQ(246, ip::linear<std::uint8_t>(a, b, 0.96488851308822631836));
    EXPECT_EQ(246, ip::linear<std::uint8_t>(a, b, 0.96769493818283081055));
}

TEST(InterpolationTests, LinearIntTest) {
    int a = -100;
    int b = 100;
    EXPECT_EQ(-68, ip::linear<int>(a, b, 0.15761308372020721436));
    EXPECT_EQ(45, ip::linear<int>(a, b, 0.7258389592170715332));
    EXPECT_EQ(94, ip::linear<int>(a, b, 0.97059279680252075195));
    EXPECT_EQ(96, ip::linear<int>(a, b, 0.98110967874526977539));
    EXPECT_EQ(91, ip::linear<int>(a, b, 0.95716696977615356445));
    EXPECT_EQ(-78, ip::linear<int>(a, b, 0.10986175388097763062));
    EXPECT_EQ(-2, ip::linear<int>(a, b, 0.48537564277648925781));
    EXPECT_EQ(59, ip::linear<int>(a, b, 0.79810583591461181641));
    EXPECT_EQ(60, ip::linear<int>(a, b, 0.80028045177459716797));
    EXPECT_EQ(-40, ip::linear<int>(a, b, 0.29702943563461303711));
    EXPECT_EQ(-71, ip::linear<int>(a, b, 0.14188633859157562256));
    EXPECT_EQ(-99, ip::linear<int>(a, b, 0.0047834841534495353699));
    EXPECT_EQ(-15, ip::linear<int>(a, b, 0.42176127433776855469));
    EXPECT_EQ(-77, ip::linear<int>(a, b, 0.11246451735496520996));
    EXPECT_EQ(83, ip::linear<int>(a, b, 0.91573554277420043945));
    EXPECT_EQ(27, ip::linear<int>(a, b, 0.63976335525512695313));
    EXPECT_EQ(58, ip::linear<int>(a, b, 0.79220730066299438477));
    EXPECT_EQ(75, ip::linear<int>(a, b, 0.8784306645393371582));
    EXPECT_EQ(91, ip::linear<int>(a, b, 0.95949244499206542969));
    EXPECT_EQ(0, ip::linear<int>(a, b, 0.50366270542144775391));
}

TEST(InterpolationTests, LinearDoubleTest) {
    double a = -123456.78889999999956;
    double b = 2345.1233999999999469;
    EXPECT_NEAR(-40963.359375, ip::linear<double>(a, b, 0.65574067831039428711), 0.005);
    EXPECT_NEAR(-23075.841796875, ip::linear<double>(a, b, 0.79792863130569458008), 0.005);
    EXPECT_NEAR(-118964.1875, ip::linear<double>(a, b, 0.035711679607629776001), 0.005);
    EXPECT_NEAR(-78005.3125, ip::linear<double>(a, b, 0.36129400134086608887), 0.005);
    EXPECT_NEAR(-16634.697265625, ip::linear<double>(a, b, 0.84912931919097900391), 0.005);
    EXPECT_NEAR(-96796.3046875, ip::linear<double>(a, b, 0.21192432940006256104), 0.005);
    EXPECT_NEAR(-5958.65576171875, ip::linear<double>(a, b, 0.93399322032928466797), 0.005);
    EXPECT_NEAR(-37740.45703125, ip::linear<double>(a, b, 0.68135952949523925781), 0.005);
    EXPECT_NEAR(-38070.609375, ip::linear<double>(a, b, 0.67873513698577880859), 0.005);
    EXPECT_NEAR(-73294.71875, ip::linear<double>(a, b, 0.39873853325843811035), 0.005);
    EXPECT_NEAR(-28131.630859375, ip::linear<double>(a, b, 0.75774013996124267578), 0.005);
    EXPECT_NEAR(-30281.947265625, ip::linear<double>(a, b, 0.74064725637435913086), 0.005);
    EXPECT_NEAR(-29969.302734375, ip::linear<double>(a, b, 0.74313247203826904297), 0.005);
    EXPECT_NEAR(-63731.23828125, ip::linear<double>(a, b, 0.47475868463516235352), 0.005);
    EXPECT_NEAR(-74113.8828125, ip::linear<double>(a, b, 0.39222702383995056152), 0.005);
    EXPECT_NEAR(-70357.3515625, ip::linear<double>(a, b, 0.42208766937255859375), 0.005);
    EXPECT_NEAR(-40996.41796875, ip::linear<double>(a, b, 0.65547788143157958984), 0.005);
    EXPECT_NEAR(-101584.21875, ip::linear<double>(a, b, 0.17386516928672790527), 0.005);
    EXPECT_NEAR(-101921.1796875, ip::linear<double>(a, b, 0.17118668556213378906), 0.005);
    EXPECT_NEAR(-85475.5390625, ip::linear<double>(a, b, 0.30191311240196228027), 0.005);
}

TEST(InterpolationTests, LinearFloatTest) {
    float a = -3.1400001049041748047;
    float b = 7.1199998855590820313;
    EXPECT_NEAR(4.1040334701538085938, ip::linear<float>(a, b, 0.70604610443115234375f), 0.0001f);
    EXPECT_NEAR(5.0400915145874023438, ip::linear<float>(a, b, 0.79727989435195922852f), 0.0001f);
    EXPECT_NEAR(-2.8133950233459472656, ip::linear<float>(a, b, 0.031832844018936157227f), 0.0001f);
    EXPECT_NEAR(0.10780739784240722656, ip::linear<float>(a, b, 0.31655043363571166992f), 0.0001f);
    EXPECT_NEAR(-0.29877042770385742188, ip::linear<float>(a, b, 0.27692297101020812988f), 0.0001f);
    EXPECT_NEAR(5.8111200332641601563, ip::linear<float>(a, b, 0.87242883443832397461f), 0.0001f);
    EXPECT_NEAR(-2.6662817001342773438, ip::linear<float>(a, b, 0.046171389520168304443f), 0.0001f);
    EXPECT_NEAR(-1.6100906133651733398, ip::linear<float>(a, b, 0.1491139829158782959f), 0.0001f);
    EXPECT_NEAR(-2.1434280872344970703, ip::linear<float>(a, b, 0.097131773829460144043f), 0.0001f);
    EXPECT_NEAR(7.05914306640625, ip::linear<float>(a, b, 0.99406850337982177734f), 0.0001f);
    EXPECT_NEAR(5.30867767333984375, ip::linear<float>(a, b, 0.82345783710479736328f), 0.0001f);
    EXPECT_NEAR(5.2927274703979492188, ip::linear<float>(a, b, 0.82190328836441040039f), 0.0001f);
    EXPECT_NEAR(3.9889419078826904297, ip::linear<float>(a, b, 0.69482862949371337891f), 0.0001f);
    EXPECT_NEAR(-1.8556249141693115234, ip::linear<float>(a, b, 0.1251827627420425415f), 0.0001f);
    EXPECT_NEAR(0.11344075202941894531, ip::linear<float>(a, b, 0.31709948182106018066f), 0.0001f);
    EXPECT_NEAR(4.696075439453125, ip::linear<float>(a, b, 0.76375001668930053711f), 0.0001f);
    EXPECT_NEAR(6.6092786788940429688, ip::linear<float>(a, b, 0.95022207498550415039f), 0.0001f);
    EXPECT_NEAR(1.8934438228607177734, ip::linear<float>(a, b, 0.49058905243873596191f), 0.0001f);
    EXPECT_NEAR(-2.7865834236145019531, ip::linear<float>(a, b, 0.034446079283952713013f), 0.0001f);
    EXPECT_NEAR(3.6685926914215087891, ip::linear<float>(a, b, 0.66360551118850708008f), 0.0001f);
}

#endif

#if ENABLE_BILINEAR_UNITTEST == 1
TEST(InterpolationTests, BiLinearTest) {
    {
        std::array<float, 4> v = {0.43874436616897583f, 0.1258966326713562f, 0.38155844807624817f, 0.21020907163619995f};
        EXPECT_FLOAT_EQ(0.2018730491399765f, ip::bilinear(v, 0.76551681756973267f, 0.051216427236795425f));
        EXPECT_FLOAT_EQ(0.19198429584503174f, ip::bilinear(v, 0.7951999306678772f, 0.036441251635551453f));
        EXPECT_FLOAT_EQ(0.3677157461643219f, ip::bilinear(v, 0.18687260150909424f, 0.40873116254806519f));
        EXPECT_FLOAT_EQ(0.29107120633125305f, ip::bilinear(v, 0.48976439237594604f, 0.4579891562461853f));
        EXPECT_FLOAT_EQ(0.3022027313709259f, ip::bilinear(v, 0.44558620452880859f, 0.48756891489028931f));
        EXPECT_FLOAT_EQ(0.26375338435173035f, ip::bilinear(v, 0.64631301164627075f, 0.79397499561309814f));
        EXPECT_FLOAT_EQ(0.25659197568893433f, ip::bilinear(v, 0.70936483144760132f, 0.92087477445602417f));
        EXPECT_FLOAT_EQ(0.24269668757915497f, ip::bilinear(v, 0.75468665361404419f, 0.80753099918365479f));
        EXPECT_FLOAT_EQ(0.33959567546844482f, ip::bilinear(v, 0.27602508664131165f, 0.70577424764633179f));
        EXPECT_FLOAT_EQ(0.226210817694664f, ip::bilinear(v, 0.67970269918441772f, 0.0028184324037283659f));
    }
    {
        std::array<float, 4> v = {0.65509802103042603f, 0.71070384979248047f, 0.16261173784732819f, 0.64396095275878906f};
        EXPECT_FLOAT_EQ(0.46022883057594299f, ip::bilinear(v, 0.11899767816066742f, 0.45603281259536743f));
        EXPECT_FLOAT_EQ(0.46587240695953369f, ip::bilinear(v, 0.49836406111717224f, 0.77391713857650757f));
        EXPECT_FLOAT_EQ(0.66033792495727539f, ip::bilinear(v, 0.95974397659301758f, 0.57375466823577881f));
        EXPECT_FLOAT_EQ(0.36929145455360413f, ip::bilinear(v, 0.34038573503494263f, 0.87675744295120239f));
        EXPECT_FLOAT_EQ(0.49100321531295776f, ip::bilinear(v, 0.58526772260665894f, 0.80817550420761108f));
        EXPECT_FLOAT_EQ(0.66048347949981689f, ip::bilinear(v, 0.22381193935871124f, 0.017773896455764771f));
        EXPECT_FLOAT_EQ(0.55509352684020996f, ip::bilinear(v, 0.75126707553863525f, 0.82124596834182739f));
        EXPECT_FLOAT_EQ(0.35417744517326355f, ip::bilinear(v, 0.25509512424468994f, 0.82084077596664429f));
        EXPECT_FLOAT_EQ(0.42275798320770264f, ip::bilinear(v, 0.50595706701278687f, 0.94007402658462524f));
        EXPECT_FLOAT_EQ(0.61355894804000854f, ip::bilinear(v, 0.69907671213150024f, 0.41266652941703796f));
    }
    {
        std::array<float, 4> v = {0.89090323448181152f, 0.42316511273384094f, 0.95929139852523804f, 0.58095669746398926f};
        EXPECT_FLOAT_EQ(0.65349161624908447f, ip::bilinear(v, 0.54721552133560181f, 0.15805758535861969f));
        EXPECT_FLOAT_EQ(0.88759720325469971f, ip::bilinear(v, 0.13862444460391998f, 0.76173120737075806f));
        EXPECT_FLOAT_EQ(0.83988469839096069f, ip::bilinear(v, 0.14929400384426117f, 0.2301560640335083f));
        EXPECT_FLOAT_EQ(0.84447485208511353f, ip::bilinear(v, 0.25750824809074402f, 0.8097345232963562f));
        EXPECT_FLOAT_EQ(0.63957118988037109f, ip::bilinear(v, 0.84071725606918335f, 0.98852157592773438f));
        EXPECT_FLOAT_EQ(0.80225908756256104f, ip::bilinear(v, 0.25428217649459839f, 0.33244827389717102f));
        EXPECT_FLOAT_EQ(0.55236387252807617f, ip::bilinear(v, 0.8142848014831543f, 0.29983171820640564f));
        EXPECT_FLOAT_EQ(0.77821803092956543f, ip::bilinear(v, 0.24352496862411499f, 0.013539126142859459f));
        EXPECT_FLOAT_EQ(0.48915567994117737f, ip::bilinear(v, 0.9292636513710022f, 0.21723784506320953f));
        EXPECT_FLOAT_EQ(0.81764668226242065f, ip::bilinear(v, 0.34998375177383423f, 0.90736472606658936f));
    }
    {
        std::array<float, 4> v = {0.19659525156021118f, 0.84846776723861694f, 0.2510838508605957f, 0.9550175666809082f};
        EXPECT_FLOAT_EQ(0.6655997633934021f, ip::bilinear(v, 0.61604470014572144f, 0.77889770269393921f));
        EXPECT_FLOAT_EQ(0.58325552940368652f, ip::bilinear(v, 0.47328883409500122f, 0.98745959997177124f));
        EXPECT_FLOAT_EQ(0.43075311183929443f, ip::bilinear(v, 0.35165950655937195f, 0.067595377564430237f));
        EXPECT_FLOAT_EQ(0.81575781106948853f, ip::bilinear(v, 0.83082860708236694f, 0.79359757900238037f));
        EXPECT_FLOAT_EQ(0.62862074375152588f, ip::bilinear(v, 0.58526408672332764f, 0.59450358152389526f));
        EXPECT_FLOAT_EQ(0.61584627628326416f, ip::bilinear(v, 0.54972362518310547f, 0.73279869556427002f));
        EXPECT_FLOAT_EQ(0.86556833982467651f, ip::bilinear(v, 0.91719365119934082f, 0.69523286819458008f));
        EXPECT_FLOAT_EQ(0.43008476495742798f, ip::bilinear(v, 0.2858390212059021f, 0.67981976270675659f));
        EXPECT_FLOAT_EQ(0.72703582048416138f, ip::bilinear(v, 0.75720024108886719f, 0.39232045412063599f));
        EXPECT_FLOAT_EQ(0.74056458473205566f, ip::bilinear(v, 0.75372910499572754f, 0.56155747175216675f));
    }
    {
        std::array<float, 4> v = {0.38044583797454834f, 0.20806805789470673f, 0.56782162189483643f, 0.52737146615982056f};
        EXPECT_FLOAT_EQ(0.44715416431427002f, ip::bilinear(v, 0.075854294002056122f, 0.40420851111412048f));
        EXPECT_FLOAT_EQ(0.43975594639778137f, ip::bilinear(v, 0.053950119763612747f, 0.35276240110397339f));
        EXPECT_FLOAT_EQ(0.44154256582260132f, ip::bilinear(v, 0.53079754114151001f, 0.59282386302947998f));
        EXPECT_FLOAT_EQ(0.34953519701957703f, ip::bilinear(v, 0.77916723489761353f, 0.35634514689445496f));
        EXPECT_FLOAT_EQ(0.51915937662124634f, ip::bilinear(v, 0.93401068449020386f, 0.96496635675430298f));
        EXPECT_FLOAT_EQ(0.38963770866394043f, ip::bilinear(v, 0.12990620732307434f, 0.15443842113018036f));
        EXPECT_FLOAT_EQ(0.3860248327255249f, ip::bilinear(v, 0.56882363557815552f, 0.39490821957588196f));
        EXPECT_FLOAT_EQ(0.39608669281005859f, ip::bilinear(v, 0.4693906307220459f, 0.38729590177536011f));
        EXPECT_FLOAT_EQ(0.51574939489364624f, ip::bilinear(v, 0.011902069672942162f, 0.72695469856262207f));
        EXPECT_FLOAT_EQ(0.41242390871047974f, ip::bilinear(v, 0.33712264895439148f, 0.38856980204582214f));
    }
}

#endif

#if ENABLE_QUADRATIC_UNITTEST == 1
TEST(InterpolationTests, QuadtraticUInt8Test) {
    std::uint8_t a = 0;
    std::uint8_t b = 255;
    std::uint8_t c = 146;
    EXPECT_EQ(243, ip::quadratic<std::uint8_t>(a, b, c, 0.43874436616897583008));
    EXPECT_EQ(98, ip::quadratic<std::uint8_t>(a, b, c, 0.12589663267135620117));
    EXPECT_EQ(227, ip::quadratic<std::uint8_t>(a, b, c, 0.38155844807624816895));
    EXPECT_EQ(151, ip::quadratic<std::uint8_t>(a, b, c, 0.21020907163619995117));
    EXPECT_EQ(242, ip::quadratic<std::uint8_t>(a, b, c, 0.76551681756973266602));
    EXPECT_EQ(42, ip::quadratic<std::uint8_t>(a, b, c, 0.051216427236795425415));
    EXPECT_EQ(234, ip::quadratic<std::uint8_t>(a, b, c, 0.79519993066787719727));
    EXPECT_EQ(30, ip::quadratic<std::uint8_t>(a, b, c, 0.036441251635551452637));
    EXPECT_EQ(137, ip::quadratic<std::uint8_t>(a, b, c, 0.18687260150909423828));
    EXPECT_EQ(235, ip::quadratic<std::uint8_t>(a, b, c, 0.40873116254806518555));
    EXPECT_EQ(253, ip::quadratic<std::uint8_t>(a, b, c, 0.48976439237594604492));
    EXPECT_EQ(247, ip::quadratic<std::uint8_t>(a, b, c, 0.45798915624618530273));
    EXPECT_EQ(244, ip::quadratic<std::uint8_t>(a, b, c, 0.44558620452880859375));
    EXPECT_EQ(253, ip::quadratic<std::uint8_t>(a, b, c, 0.48756891489028930664));
    EXPECT_EQ(4, ip::quadratic<std::uint8_t>(a, b, c, 0.64631301164627075195));
    EXPECT_EQ(235, ip::quadratic<std::uint8_t>(a, b, c, 0.79397499561309814453));
    EXPECT_EQ(253, ip::quadratic<std::uint8_t>(a, b, c, 0.70936483144760131836));
    EXPECT_EQ(187, ip::quadratic<std::uint8_t>(a, b, c, 0.92087477445602416992));
    EXPECT_EQ(244, ip::quadratic<std::uint8_t>(a, b, c, 0.75468665361404418945));
    EXPECT_EQ(231, ip::quadratic<std::uint8_t>(a, b, c, 0.80753099918365478516));
}

TEST(InterpolationTests, QuadtraticIntTest) {
    int a = -100;
    int b = 100;
    int c = 129;
    EXPECT_EQ(31, ip::quadratic<int>(a, b, c, 0.27602508664131164551));
    EXPECT_EQ(132, ip::quadratic<int>(a, b, c, 0.70577424764633178711));
    EXPECT_EQ(130, ip::quadratic<int>(a, b, c, 0.67970269918441772461));
    EXPECT_EQ(-98, ip::quadratic<int>(a, b, c, 0.0028184324037283658981));
    EXPECT_EQ(127, ip::quadratic<int>(a, b, c, 0.65509802103042602539));
    EXPECT_EQ(133, ip::quadratic<int>(a, b, c, 0.71070384979248046875));
    EXPECT_EQ(-16, ip::quadratic<int>(a, b, c, 0.16261173784732818604));
    EXPECT_EQ(125, ip::quadratic<int>(a, b, c, 0.6439609527587890625));
    EXPECT_EQ(-36, ip::quadratic<int>(a, b, c, 0.11899767816066741943));
    EXPECT_EQ(89, ip::quadratic<int>(a, b, c, 0.45603281259536743164));
    EXPECT_EQ(99, ip::quadratic<int>(a, b, c, 0.49836406111717224121));
    EXPECT_EQ(137, ip::quadratic<int>(a, b, c, 0.77391713857650756836));
    EXPECT_EQ(132, ip::quadratic<int>(a, b, c, 0.95974397659301757813));
    EXPECT_EQ(115, ip::quadratic<int>(a, b, c, 0.57375466823577880859));
    EXPECT_EQ(54, ip::quadratic<int>(a, b, c, 0.34038573503494262695));
    EXPECT_EQ(137, ip::quadratic<int>(a, b, c, 0.87675744295120239258));
    EXPECT_EQ(117, ip::quadratic<int>(a, b, c, 0.58526772260665893555));
    EXPECT_EQ(138, ip::quadratic<int>(a, b, c, 0.80817550420761108398));
    EXPECT_EQ(10, ip::quadratic<int>(a, b, c, 0.22381193935871124268));
    EXPECT_EQ(-89, ip::quadratic<int>(a, b, c, 0.017773896455764770508));
}

TEST(InterpolationTests, QuadtraticDoubleTest) {
    double a = -123456.7890625;
    double b = 2345.123291015625;
    double c = 78431.400999999998021;
    EXPECT_NEAR(46795.371501252593589, ip::quadratic<double>(a, b, c, 0.75126707553863525391), 0.005);
    EXPECT_NEAR(56939.681543512619101, ip::quadratic<double>(a, b, c, 0.82124596834182739258), 0.005);
    EXPECT_NEAR(-53062.006827123223047, ip::quadratic<double>(a, b, c, 0.25509512424468994141), 0.005);
    EXPECT_NEAR(56883.754956706237863, ip::quadratic<double>(a, b, c, 0.82084077596664428711), 0.005);
    EXPECT_NEAR(3544.2575929693989565, ip::quadratic<double>(a, b, c, 0.50595706701278686523), 0.005);
    EXPECT_NEAR(71934.500150714040501, ip::quadratic<double>(a, b, c, 0.94007402658462524414), 0.005);
    EXPECT_NEAR(38595.747488972840074, ip::quadratic<double>(a, b, c, 0.69907671213150024414), 0.005);
    EXPECT_NEAR(-16044.849249120932654, ip::quadratic<double>(a, b, c, 0.41266652941703796387), 0.005);
    EXPECT_NEAR(66070.239206885555177, ip::quadratic<double>(a, b, c, 0.89090323448181152344), 0.005);
    EXPECT_NEAR(-13753.935498106086015, ip::quadratic<double>(a, b, c, 0.42316511273384094238), 0.005);
    EXPECT_NEAR(74095.746248850948177, ip::quadratic<double>(a, b, c, 0.95929139852523803711), 0.005);
    EXPECT_NEAR(18037.652111651696032, ip::quadratic<double>(a, b, c, 0.58095669746398925781), 0.005);
    EXPECT_NEAR(11655.716537397795037, ip::quadratic<double>(a, b, c, 0.54721552133560180664), 0.005);
    EXPECT_NEAR(-78314.976498921096209, ip::quadratic<double>(a, b, c, 0.15805758535861968994), 0.005);
    EXPECT_NEAR(-83597.298364941001637, ip::quadratic<double>(a, b, c, 0.13862444460391998291), 0.01);
    EXPECT_NEAR(48374.197004888184892, ip::quadratic<double>(a, b, c, 0.76173120737075805664), 0.005);
    EXPECT_NEAR(-80687.791348143597133, ip::quadratic<double>(a, b, c, 0.14929400384426116943), 0.005);
    EXPECT_NEAR(-59373.342012107263145, ip::quadratic<double>(a, b, c, 0.23015606403350830078), 0.005);
    EXPECT_NEAR(-52457.879807783509023, ip::quadratic<double>(a, b, c, 0.25750824809074401855), 0.005);
    EXPECT_NEAR(55337.87775399126258, ip::quadratic<double>(a, b, c, 0.80973452329635620117), 0.005);
}

TEST(InterpolationTests, QuadtraticFloatTest) {
    float a = -3.1433999538421630859;
    float b = 7.1199998855590820313;
    float c = 4.0999999046325683594;
    EXPECT_NEAR(6.5038585662841796875, ip::quadratic<float>(a, b, c, 0.84071725606918334961), 0.0001f);
    EXPECT_NEAR(4.3183016777038574219, ip::quadratic<float>(a, b, c, 0.988521575927734375), 0.0001f);
    EXPECT_NEAR(3.7361369132995605469, ip::quadratic<float>(a, b, c, 0.25428217649459838867), 0.0001f);
    EXPECT_NEAR(5.1605310440063476563, ip::quadratic<float>(a, b, c, 0.33244827389717102051), 0.0001f);
    EXPECT_NEAR(6.7723560333251953125, ip::quadratic<float>(a, b, c, 0.81428480148315429688), 0.0001f);
    EXPECT_NEAR(4.6056394577026367188, ip::quadratic<float>(a, b, c, 0.29983171820640563965), 0.0001f);
    EXPECT_NEAR(3.5146992206573486328, ip::quadratic<float>(a, b, c, 0.24352496862411499023), 0.0001f);
    EXPECT_NEAR(-2.6905093193054199219, ip::quadratic<float>(a, b, c, 0.013539126142859458923), 0.0001f);
    EXPECT_NEAR(5.3339366912841796875, ip::quadratic<float>(a, b, c, 0.92926365137100219727), 0.0001f);
    EXPECT_NEAR(2.9477071762084960938, ip::quadratic<float>(a, b, c, 0.21723784506320953369), 0.0001f);
    EXPECT_NEAR(5.4354891777038574219, ip::quadratic<float>(a, b, c, 0.34998375177383422852), 0.0001f);
    EXPECT_NEAR(5.6620502471923828125, ip::quadratic<float>(a, b, c, 0.90736472606658935547), 0.0001f);
    EXPECT_NEAR(2.4767262935638427734, ip::quadratic<float>(a, b, c, 0.19659525156021118164), 0.0001f);
    EXPECT_NEAR(6.4180908203125, ip::quadratic<float>(a, b, c, 0.84846776723861694336), 0.0001f);
    EXPECT_NEAR(3.6709418296813964844, ip::quadratic<float>(a, b, c, 0.25108385086059570313), 0.0001f);
    EXPECT_NEAR(4.9154577255249023438, ip::quadratic<float>(a, b, c, 0.95501756668090820313), 0.0001f);
    EXPECT_NEAR(7.6027994155883789063, ip::quadratic<float>(a, b, c, 0.61604470014572143555), 0.0001f);
    EXPECT_NEAR(7.0736980438232421875, ip::quadratic<float>(a, b, c, 0.77889770269393920898), 0.0001f);
    EXPECT_NEAR(6.9075651168823242188, ip::quadratic<float>(a, b, c, 0.4732888340950012207), 0.0001f);
    EXPECT_NEAR(4.3381447792053222656, ip::quadratic<float>(a, b, c, 0.98745959997177124023), 0.0001f);
}

#endif

#if ENABLE_BIQUADRATIC_UNITTEST == 1
TEST(InterpolationTests, BiQuadraticTest) {
    {
        std::array<float, 9> v = {0.35165950655937194824, 0.067595377564430236816, 0.83082860708236694336, 0.79359757900238037109, 0.58526408672332763672,
                                  0.59450358152389526367, 0.54972362518310546875,  0.73279869556427001953, 0.91719365119934082031};
        EXPECT_FLOAT_EQ(0.43489718437194824219f, ip::biQuadratic(v, 0.69523286819458007813f, 0.28583902120590209961f));
        EXPECT_FLOAT_EQ(0.69795429706573486328f, ip::biQuadratic(v, 0.6798197627067565918f, 0.7572002410888671875f));
        EXPECT_FLOAT_EQ(0.7143421173095703125f, ip::biQuadratic(v, 0.39232045412063598633f, 0.75372910499572753906f));
        EXPECT_FLOAT_EQ(0.48864188790321350098f, ip::biQuadratic(v, 0.56155747175216674805f, 0.38044583797454833984f));
        EXPECT_FLOAT_EQ(0.70991975069046020508f, ip::biQuadratic(v, 0.20806805789470672607f, 0.56782162189483642578f));
        EXPECT_FLOAT_EQ(0.17937514185905456543f, ip::biQuadratic(v, 0.52737146615982055664f, 0.075854294002056121826f));
        EXPECT_FLOAT_EQ(0.12515047192573547363f, ip::biQuadratic(v, 0.4042085111141204834f, 0.053950119763612747192f));
        EXPECT_FLOAT_EQ(0.64260870218276977539f, ip::biQuadratic(v, 0.35276240110397338867f, 0.53079754114151000977f));
        EXPECT_FLOAT_EQ(0.71027529239654541016f, ip::biQuadratic(v, 0.59282386302947998047f, 0.77916723489761352539f));
        EXPECT_FLOAT_EQ(0.70250666141510009766f, ip::biQuadratic(v, 0.35634514689445495605f, 0.93401068449020385742f));
    }
    {
        std::array<float, 9> v = {0.96496635675430297852, 0.12990620732307434082, 0.15443842113018035889, 0.56882363557815551758, 0.39490821957588195801,
                                  0.46939063072204589844, 0.38729590177536010742, 0.01190206967294216156, 0.72695469856262207031};
        EXPECT_FLOAT_EQ(0.44386541843414306641f, ip::biQuadratic(v, 0.33712264895439147949f, 0.38856980204582214355f));
        EXPECT_FLOAT_EQ(0.20913894474506378174f, ip::biQuadratic(v, 0.16218230128288269043f, 0.92749285697937011719f));
        EXPECT_FLOAT_EQ(0.38814392685890197754f, ip::biQuadratic(v, 0.79428452253341674805f, 0.43611755967140197754f));
        EXPECT_FLOAT_EQ(0.18609178066253662109f, ip::biQuadratic(v, 0.31121504306793212891f, 0.86267817020416259766f));
        EXPECT_FLOAT_EQ(0.36333677172660827637f, ip::biQuadratic(v, 0.52853316068649291992f, 0.62036001682281494141f));
        EXPECT_FLOAT_EQ(0.58805495500564575195f, ip::biQuadratic(v, 0.16564872860908508301f, 0.11954718083143234253f));
        EXPECT_FLOAT_EQ(0.38880449533462524414f, ip::biQuadratic(v, 0.60198193788528442383f, 0.47195678949356079102f));
        EXPECT_FLOAT_EQ(0.48320111632347106934f, ip::biQuadratic(v, 0.26297128200531005859f, 0.34021970629692077637f));
        EXPECT_FLOAT_EQ(0.39237007498741149902f, ip::biQuadratic(v, 0.65407907962799072266f, 0.52984195947647094727f));
        EXPECT_FLOAT_EQ(0.3633708953857421875f, ip::biQuadratic(v, 0.68921452760696411133f, 0.7161006927490234375f));
    }
    {
        std::array<float, 9> v = {0.74815160036087036133, 0.98837941884994506836, 0.45054158568382263184, 0.72049343585968017578, 0.083821378648281097412,
                                  0.91257750988006591797, 0.22897696495056152344, 0.50549852848052978516, 0.91333734989166259766};
        EXPECT_FLOAT_EQ(0.56548023223876953125f, ip::biQuadratic(v, 0.55826878547668457031f, 0.15237802267074584961f));
        EXPECT_FLOAT_EQ(0.20972362160682678223f, ip::biQuadratic(v, 0.50319004058837890625f, 0.82581698894500732422f));
        EXPECT_FLOAT_EQ(0.064780548214912414551f, ip::biQuadratic(v, 0.4624741971492767334f, 0.53834241628646850586f));
        EXPECT_FLOAT_EQ(0.52953439950942993164f, ip::biQuadratic(v, 0.54659193754196166992f, 0.99613469839096069336f));
        EXPECT_FLOAT_EQ(0.77002573013305664063f, ip::biQuadratic(v, 0.44758439064025878906f, 0.078175529837608337402f));
        EXPECT_FLOAT_EQ(0.51756936311721801758f, ip::biQuadratic(v, 0.85445100069046020508f, 0.44267827272415161133f));
        EXPECT_FLOAT_EQ(0.66401565074920654297f, ip::biQuadratic(v, 0.60423147678375244141f, 0.10665277391672134399f));
        EXPECT_FLOAT_EQ(0.42574366927146911621f, ip::biQuadratic(v, 0.49854418635368347168f, 0.96189808845520019531f));
        EXPECT_FLOAT_EQ(0.49197223782539367676f, ip::biQuadratic(v, 0.97992563247680664063f, 0.0046342257410287857056f));
        EXPECT_FLOAT_EQ(0.445667266845703125f, ip::biQuadratic(v, 0.034317314624786376953f, 0.77491044998168945313f));
    }
    {
        std::array<float, 9> v = {0.97700202465057373047,  0.81730324029922485352, 0.36318644881248474121, 0.86869472265243530273, 0.67951971292495727539,
                                  0.084435850381851196289, 0.3462333977222442627,  0.39978265762329101563, 0.85587513446807861328};
        EXPECT_FLOAT_EQ(0.93674457073211669922f, ip::biQuadratic(v, 0.25987040996551513672f, 0.045059543102979660034f));
        EXPECT_FLOAT_EQ(0.40206032991409301758f, ip::biQuadratic(v, 0.80006849765777587891f, 0.66011947393417358398f));
        EXPECT_FLOAT_EQ(0.57831197977066040039f, ip::biQuadratic(v, 0.43141382932662963867f, 0.74994099140167236328f));
        EXPECT_FLOAT_EQ(0.32554450631141662598f, ip::biQuadratic(v, 0.91064757108688354492f, 0.13299603760242462158f));
        EXPECT_FLOAT_EQ(0.34492278099060058594f, ip::biQuadratic(v, 0.18184702098369598389f, 0.98236054182052612305f));
        EXPECT_FLOAT_EQ(0.93818712234497070313f, ip::biQuadratic(v, 0.26380291581153869629f, 0.095355175435543060303f));
        EXPECT_FLOAT_EQ(0.95412749052047729492f, ip::biQuadratic(v, 0.1455389857292175293f, 0.28267329931259155273f));
        EXPECT_FLOAT_EQ(0.58481997251510620117f, ip::biQuadratic(v, 0.13606855273246765137f, 0.80211144685745239258f));
        EXPECT_FLOAT_EQ(0.43189477920532226563f, ip::biQuadratic(v, 0.86929219961166381836f, 0.077557027339935302734f));
        EXPECT_FLOAT_EQ(0.57076263427734375f, ip::biQuadratic(v, 0.57970458269119262695f, 0.62738436460494995117f));
    }
    {
        std::array<float, 9> v = {0.54986017942428588867, 0.0080939121544361114502, 0.14495480060577392578, 0.6802870631217956543, 0.85303109884262084961,
                                  0.53393310308456420898, 0.62205511331558227539,   0.43866682052612304688, 0.35095238685607910156};
        EXPECT_FLOAT_EQ(0.81169378757476806641f, ip::biQuadratic(v, 0.19955120980739593506f, 0.51324951648712158203f));
        EXPECT_FLOAT_EQ(0.74186229705810546875f, ip::biQuadratic(v, 0.13800132274627685547f, 0.40180802345275878906f));
        EXPECT_FLOAT_EQ(0.26844570040702819824f, ip::biQuadratic(v, 0.38233295083045959473f, 0.075966686010360717773f));
        EXPECT_FLOAT_EQ(0.49542948603630065918f, ip::biQuadratic(v, 0.7624213099479675293f, 0.2399161607027053833f));
        EXPECT_FLOAT_EQ(0.5695896148681640625f, ip::biQuadratic(v, 0.040471110492944717407f, 0.12331893295049667358f));
        EXPECT_FLOAT_EQ(0.53614902496337890625f, ip::biQuadratic(v, 0.25295597314834594727f, 0.18390779197216033936f));
        EXPECT_FLOAT_EQ(0.56962573528289794922f, ip::biQuadratic(v, 0.50477099418640136719f, 0.23995251953601837158f));
        EXPECT_FLOAT_EQ(0.66036301851272583008f, ip::biQuadratic(v, 0.82260495424270629883f, 0.41726705431938171387f));
        EXPECT_FLOAT_EQ(0.19842122495174407959f, ip::biQuadratic(v, 0.9817231297492980957f, 0.049654424190521240234f));
        EXPECT_FLOAT_EQ(0.51511466503143310547f, ip::biQuadratic(v, 0.82345539331436157227f, 0.90271610021591186523f));
    }
}
#endif

#if ENABLE_BARYCENTRIC_UNITTEST == 1
TEST(InterpolationTests, BarycentricTest) {
    {
        std::array<float, 4> v = {0.90018320083618164063f, 0.2304881662130355835f, 0.19449537992477416992f, 0.84430879354476928711f};
        EXPECT_FLOAT_EQ(0.27595853805541992188f, ip::barycentric(v, 0.88599812984466552734f, 0.19476428627967834473f));
        EXPECT_FLOAT_EQ(0.44526773691177368164f, ip::barycentric(v, 0.44122347235679626465f, 0.22592177987098693848f));
        EXPECT_FLOAT_EQ(0.6807162165641784668f, ip::barycentric(v, 0.14782901108264923096f, 0.1707080453634262085f));
        EXPECT_FLOAT_EQ(0.57912969589233398438f, ip::barycentric(v, 0.23950245976448059082f, 0.2276642918586730957f));
        EXPECT_FLOAT_EQ(0.36774095892906188965f, ip::barycentric(v, 0.79965317249298095703f, 0.43569868803024291992f));
        EXPECT_FLOAT_EQ(0.36386623978614807129f, ip::barycentric(v, 0.47301506996154785156f, 0.31110230088233947754f));
        EXPECT_FLOAT_EQ(0.20583251118659973145f, ip::barycentric(v, 0.089823156595230102539f, 0.92337965965270996094f));
        EXPECT_FLOAT_EQ(0.26358252763748168945f, ip::barycentric(v, 0.64455056190490722656f, 0.43020740151405334473f));
        EXPECT_FLOAT_EQ(0.34580099582672119141f, ip::barycentric(v, 0.63306367397308349609f, 0.18481631577014923096f));
        EXPECT_FLOAT_EQ(0.51584875583648681641f, ip::barycentric(v, 0.58438223600387573242f, 0.90488094091415405273f));
    }
    {
        std::array<float, 4> v = {0.72665441036224365234f, 0.97974836826324462891f, 0.35463812947273254395f, 0.43886998295783996582f};
        EXPECT_FLOAT_EQ(0.85752308368682861328f, ip::barycentric(v, 0.68040663003921508789f, 0.11111921817064285278f));
        EXPECT_FLOAT_EQ(0.80966895818710327148f, ip::barycentric(v, 0.70732152462005615234f, 0.25806468725204467773f));
        EXPECT_FLOAT_EQ(0.615688323974609375f, ip::barycentric(v, 0.16232851147651672363f, 0.40871983766555786133f));
        EXPECT_FLOAT_EQ(0.53919124603271484375f, ip::barycentric(v, 0.13373638689517974854f, 0.59489607810974121094f));
        EXPECT_FLOAT_EQ(0.74288731813430786133f, ip::barycentric(v, 0.44955608248710632324f, 0.26221174001693725586f));
        EXPECT_FLOAT_EQ(0.51303064823150634766f, ip::barycentric(v, 0.042054124176502227783f, 0.60284310579299926758f));
        EXPECT_FLOAT_EQ(0.57799869775772094727f, ip::barycentric(v, 0.79736411571502685547f, 0.71121579408645629883f));
        EXPECT_FLOAT_EQ(0.68656837940216064453f, ip::barycentric(v, 0.1675557941198348999f, 0.22174672782421112061f));
        EXPECT_FLOAT_EQ(0.89334845542907714844f, ip::barycentric(v, 0.83121430873870849609f, 0.11741765588521957397f));
        EXPECT_FLOAT_EQ(0.69853246212005615234f, ip::barycentric(v, 0.32496353983879089355f, 0.29667586088180541992f));
    }
    {
        std::array<float, 4> v = {0.65577989816665649414f, 0.31877830624580383301f, 0.42018994688987731934f, 0.42416676878929138184f};
        EXPECT_FLOAT_EQ(0.37143340706825256348f, ip::barycentric(v, 0.78190916776657104492f, 0.5078582763671875f));
        EXPECT_FLOAT_EQ(0.5974871516227722168f, ip::barycentric(v, 0.11319253593683242798f, 0.085515789687633514404f));
        EXPECT_FLOAT_EQ(0.3464151918888092041f, ip::barycentric(v, 0.9935347437858581543f, 0.26248222589492797852f));
        EXPECT_FLOAT_EQ(0.40587854385375976563f, ip::barycentric(v, 0.18157297372817993164f, 0.8010146021842956543f));
        EXPECT_FLOAT_EQ(0.39178678393363952637f, ip::barycentric(v, 0.76293140649795532227f, 0.029220281168818473816f));
        EXPECT_FLOAT_EQ(0.41374951601028442383f, ip::barycentric(v, 0.2659206688404083252f, 0.92885416746139526367f));
        EXPECT_FLOAT_EQ(0.40144634246826171875f, ip::barycentric(v, 0.24413827061653137207f, 0.73033088445663452148f));
        EXPECT_FLOAT_EQ(0.50671952962875366211f, ip::barycentric(v, 0.10073848813772201538f, 0.48860898613929748535f));
        EXPECT_FLOAT_EQ(0.4034461677074432373f, ip::barycentric(v, 0.3443279266357421875f, 0.57852506637573242188f));
        EXPECT_FLOAT_EQ(0.50496941804885864258f, ip::barycentric(v, 0.28162732720375061035f, 0.23728357255458831787f));
    }
    {
        std::array<float, 4> v = {0.96864038705825805664f, 0.45884883403778076172f, 0.21377274394035339355f, 0.96308851242065429688f};
        EXPECT_FLOAT_EQ(0.43928575515747070313f, ip::barycentric(v, 0.60592818260192871094f, 0.54680573940277099609f));
        EXPECT_FLOAT_EQ(0.45975792407989501953f, ip::barycentric(v, 0.22655132412910461426f, 0.52113580703735351563f));
        EXPECT_FLOAT_EQ(0.69700503349304199219f, ip::barycentric(v, 0.18990549445152282715f, 0.23159438371658325195f));
        EXPECT_FLOAT_EQ(0.39486953616142272949f, ip::barycentric(v, 0.40157148241996765137f, 0.48889774084091186523f));
        EXPECT_FLOAT_EQ(0.33389413356781005859f, ip::barycentric(v, 0.41329061985015869141f, 0.62406009435653686523f));
        EXPECT_FLOAT_EQ(0.36924070119857788086f, ip::barycentric(v, 0.17015227675437927246f, 0.67913556098937988281f));
        EXPECT_FLOAT_EQ(0.51762467622756958008f, ip::barycentric(v, 0.29905182123184204102f, 0.39551520347595214844f));
        EXPECT_FLOAT_EQ(0.37172514200210571289f, ip::barycentric(v, 0.63646858930587768555f, 0.36743664741516113281f));
        EXPECT_FLOAT_EQ(0.32128965854644775391f, ip::barycentric(v, 0.15157416462898254395f, 0.98798197507858276367f));
        EXPECT_FLOAT_EQ(0.54799890518188476563f, ip::barycentric(v, 0.76924318075180053711f, 0.037738863378763198853f));
    }
    {
        std::array<float, 4> v = {0.88396859169006347656f, 0.88516801595687866211f, 0.95922160148620605469f, 0.91328680515289306641f};
        EXPECT_FLOAT_EQ(0.94390547275543212891f, ip::barycentric(v, 0.01806627027690410614f, 0.7961838841438293457f));
        EXPECT_FLOAT_EQ(0.89209604263305664063f, ip::barycentric(v, 0.58284640312194824219f, 0.098712280392646789551f));
        EXPECT_FLOAT_EQ(0.90324103832244873047f, ip::barycentric(v, 0.76685410737991333008f, 0.26187118887901306152f));
        EXPECT_FLOAT_EQ(0.90959835052490234375f, ip::barycentric(v, 0.32779777050018310547f, 0.33535683155059814453f));
        EXPECT_FLOAT_EQ(0.93527495861053466797f, ip::barycentric(v, 0.12906616926193237305f, 0.67972797155380249023f));
        EXPECT_FLOAT_EQ(0.8945948481559753418f, ip::barycentric(v, 0.29196077585220336914f, 0.13655313849449157715f));
        EXPECT_FLOAT_EQ(0.91247105598449707031f, ip::barycentric(v, 0.84710967540740966797f, 0.72122752666473388672f));
        EXPECT_FLOAT_EQ(0.89227950572967529297f, ip::barycentric(v, 0.2307643890380859375f, 0.10676186531782150269f));
        EXPECT_FLOAT_EQ(0.92642760276794433594f, ip::barycentric(v, 0.50197440385818481445f, 0.65375733375549316406f));
        EXPECT_FLOAT_EQ(0.92115861177444458008f, ip::barycentric(v, 0.0015979039017111063004f, 0.49417394399642944336f));
    }
}

#endif

}  // namespace inviwo