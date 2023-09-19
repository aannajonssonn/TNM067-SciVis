#include <warn/push>
#include <warn/ignore/all>
#include <gtest/gtest.h>
#include <warn/pop>

#include <modules/tnm067lab1/processors/imageupsampler.h>

namespace inviwo {

void test_vec2(vec2 e, vec2 r) {
    EXPECT_DOUBLE_EQ(e.x, r.x);
    EXPECT_DOUBLE_EQ(e.y, r.y);
}

TEST(ImageUpsamplerTests, SameSizeTest) {
    auto a = ImageUpsampler::convertCoordinate(ivec2(0), size2_t(10, 10), size2_t(10, 10));
    auto b = ImageUpsampler::convertCoordinate(ivec2(2), size2_t(10, 10), size2_t(10, 10));
    auto c = ImageUpsampler::convertCoordinate(ivec2(2, 3), size2_t(10, 10), size2_t(10, 10));
    auto d = ImageUpsampler::convertCoordinate(ivec2(10, 3), size2_t(10, 10), size2_t(10, 10));
    auto e = ImageUpsampler::convertCoordinate(ivec2(10, 10), size2_t(10, 10), size2_t(10, 10));
    test_vec2(dvec2(0), a);
    test_vec2(dvec2(2), b);
    test_vec2(dvec2(2, 3), c);
    test_vec2(dvec2(10, 3), d);
    test_vec2(dvec2(10, 10), e);
}

TEST(ImageUpsamplerTests, SizeConversionTest) {
    test_vec2(dvec2(272.3484486873508672, 99.698412698412710142), ImageUpsampler::convertCoordinate(ivec2(988, 571), size2_t(231, 33), size2_t(838, 189)));
    test_vec2(dvec2(193.23508353221956213, 21.650793650793648482), ImageUpsampler::convertCoordinate(ivec2(701, 124), size2_t(231, 33), size2_t(838, 189)));
    test_vec2(dvec2(181.1062052505966733, 113.84126984126984894), ImageUpsampler::convertCoordinate(ivec2(657, 652), size2_t(231, 33), size2_t(838, 189)));
    test_vec2(dvec2(175.86873508353221496, 106.8571428571428612), ImageUpsampler::convertCoordinate(ivec2(638, 612), size2_t(231, 33), size2_t(838, 189)));
    test_vec2(dvec2(42.451073985680196188, 83.111111111111114269), ImageUpsampler::convertCoordinate(ivec2(154, 476), size2_t(231, 33), size2_t(838, 189)));
    test_vec2(dvec2(239.26968973747017344, 109.65079365079364493), ImageUpsampler::convertCoordinate(ivec2(868, 628), size2_t(231, 33), size2_t(838, 189)));
    test_vec2(dvec2(185.7923627684964174, 137.41269841269840413), ImageUpsampler::convertCoordinate(ivec2(674, 787), size2_t(231, 33), size2_t(838, 189)));
    test_vec2(dvec2(21.501193317422433893, 133.74603174603174693), ImageUpsampler::convertCoordinate(ivec2(78, 766), size2_t(231, 33), size2_t(838, 189)));
    test_vec2(dvec2(160.7076372315035826, 108.77777777777777146), ImageUpsampler::convertCoordinate(ivec2(583, 623), size2_t(231, 33), size2_t(838, 189)));
    test_vec2(dvec2(261.87350835322200737, 140.03174603174605295), ImageUpsampler::convertCoordinate(ivec2(950, 802), size2_t(231, 33), size2_t(838, 189)));
    test_vec2(dvec2(292.51764705882351336, 456.65174129353232502), ImageUpsampler::convertCoordinate(ivec2(666, 789), size2_t(112, 349), size2_t(255, 603)));
    test_vec2(dvec2(144.94117647058823195, 270.86567164179103884), ImageUpsampler::convertCoordinate(ivec2(330, 468), size2_t(112, 349), size2_t(255, 603)));
    test_vec2(dvec2(270.1176470588235361, 301.54063018242118233), ImageUpsampler::convertCoordinate(ivec2(615, 521), size2_t(112, 349), size2_t(255, 603)));
    test_vec2(dvec2(412.42352941176466175, 35.883913764510779743), ImageUpsampler::convertCoordinate(ivec2(939, 62), size2_t(112, 349), size2_t(255, 603)));
    test_vec2(dvec2(361.91372549019610005, 513.95024875621891169), ImageUpsampler::convertCoordinate(ivec2(824, 888), size2_t(112, 349), size2_t(255, 603)));
    test_vec2(dvec2(325.89803921568625356, 481.53897180762851349), ImageUpsampler::convertCoordinate(ivec2(742, 832), size2_t(112, 349), size2_t(255, 603)));
    test_vec2(dvec2(4.3921568627450984224, 578.19402985074623302), ImageUpsampler::convertCoordinate(ivec2(10, 999), size2_t(112, 349), size2_t(255, 603)));
    test_vec2(dvec2(13.615686274509803511, 248.29353233830843806), ImageUpsampler::convertCoordinate(ivec2(31, 429), size2_t(112, 349), size2_t(255, 603)));
    test_vec2(dvec2(324.58039215686272883, 416.13764510779435568), ImageUpsampler::convertCoordinate(ivec2(739, 719), size2_t(112, 349), size2_t(255, 603)));
    test_vec2(dvec2(137.47450980392159181, 335.10945273631841701), ImageUpsampler::convertCoordinate(ivec2(313, 579), size2_t(112, 349), size2_t(255, 603)));
    test_vec2(dvec2(132.32876712328766189, 154.036858974358978), ImageUpsampler::convertCoordinate(ivec2(161, 347), size2_t(720, 277), size2_t(876, 624)));
    test_vec2(dvec2(433.97260273972602818, 241.0432692307692264), ImageUpsampler::convertCoordinate(ivec2(528, 543), size2_t(720, 277), size2_t(876, 624)));
    test_vec2(dvec2(112.60273972602739434, 372.88461538461541522), ImageUpsampler::convertCoordinate(ivec2(137, 840), size2_t(720, 277), size2_t(876, 624)));
    test_vec2(dvec2(498.08219178082191547, 178.00801282051284602), ImageUpsampler::convertCoordinate(ivec2(606, 401), size2_t(720, 277), size2_t(876, 624)));
    test_vec2(dvec2(39.452054794520549308, 310.2932692307692264), ImageUpsampler::convertCoordinate(ivec2(48, 699), size2_t(720, 277), size2_t(876, 624)));
    test_vec2(dvec2(577.80821917808225407, 154.4807692307692264), ImageUpsampler::convertCoordinate(ivec2(703, 348), size2_t(720, 277), size2_t(876, 624)));
    test_vec2(dvec2(381.3698630136985912, 152.26121794871795601), ImageUpsampler::convertCoordinate(ivec2(464, 343), size2_t(720, 277), size2_t(876, 624)));
    test_vec2(dvec2(70.684931506849309812, 360.45512820512823282), ImageUpsampler::convertCoordinate(ivec2(86, 812), size2_t(720, 277), size2_t(876, 624)));
    test_vec2(dvec2(211.23287671232878893, 36.844551282051284602), ImageUpsampler::convertCoordinate(ivec2(257, 83), size2_t(720, 277), size2_t(876, 624)));
    test_vec2(dvec2(18.082191780821915472, 319.17147435897430796), ImageUpsampler::convertCoordinate(ivec2(22, 719), size2_t(720, 277), size2_t(876, 624)));
    test_vec2(dvec2(16.440129449838188691, 149.07975460122699474), ImageUpsampler::convertCoordinate(ivec2(127, 500), size2_t(80, 243), size2_t(618, 815)));
    test_vec2(dvec2(55.533980582524272052, 156.83190184049081495), ImageUpsampler::convertCoordinate(ivec2(429, 526), size2_t(80, 243), size2_t(618, 815)));
    test_vec2(dvec2(69.255663430420710824, 188.43680981595090884), ImageUpsampler::convertCoordinate(ivec2(535, 632), size2_t(80, 243), size2_t(618, 815)));
    test_vec2(dvec2(19.417475728155338288, 49.196319018404906842), ImageUpsampler::convertCoordinate(ivec2(150, 165), size2_t(80, 243), size2_t(618, 815)));
    test_vec2(dvec2(46.472491909385112763, 13.119018404907976105), ImageUpsampler::convertCoordinate(ivec2(359, 44), size2_t(80, 243), size2_t(618, 815)));
    test_vec2(dvec2(60.194174757281551535, 44.127607361963193), ImageUpsampler::convertCoordinate(ivec2(465, 148), size2_t(80, 243), size2_t(618, 815)));
    test_vec2(dvec2(95.663430420711975444, 228.68834355828221305), ImageUpsampler::convertCoordinate(ivec2(739, 767), size2_t(80, 243), size2_t(618, 815)));
    test_vec2(dvec2(15.533980582524272052, 274.008588957055224), ImageUpsampler::convertCoordinate(ivec2(120, 919), size2_t(80, 243), size2_t(618, 815)));
    test_vec2(dvec2(34.563106796116500163, 168.46012269938648842), ImageUpsampler::convertCoordinate(ivec2(267, 565), size2_t(80, 243), size2_t(618, 815)));
    test_vec2(dvec2(21.618122977346278191, 168.46012269938648842), ImageUpsampler::convertCoordinate(ivec2(167, 565), size2_t(80, 243), size2_t(618, 815)));
    test_vec2(dvec2(789.39058171745148229, 508.0962800875273615), ImageUpsampler::convertCoordinate(ivec2(805, 645), size2_t(354, 720), size2_t(361, 914)));
    test_vec2(dvec2(446.17728531855954088, 374.17943107221009313), ImageUpsampler::convertCoordinate(ivec2(455, 475), size2_t(354, 720), size2_t(361, 914)));
    test_vec2(dvec2(535.41274238227151727, 316.67396061269147367), ImageUpsampler::convertCoordinate(ivec2(546, 402), size2_t(354, 720), size2_t(361, 914)));
    test_vec2(dvec2(251.03601108033240052, 503.36980306345731151), ImageUpsampler::convertCoordinate(ivec2(256, 639), size2_t(354, 720), size2_t(361, 914)));
    test_vec2(dvec2(612.88088642659272409, 513.61050328227565842), ImageUpsampler::convertCoordinate(ivec2(625, 652), size2_t(354, 720), size2_t(361, 914)));
    test_vec2(dvec2(903.14127423822708352, 61.444201312910287527), ImageUpsampler::convertCoordinate(ivec2(921, 78), size2_t(354, 720), size2_t(361, 914)));
    test_vec2(dvec2(382.43767313019384346, 484.46389496717728207), ImageUpsampler::convertCoordinate(ivec2(390, 615), size2_t(354, 720), size2_t(361, 914)));
    test_vec2(dvec2(905.10249307479216441, 97.680525164113788605), ImageUpsampler::convertCoordinate(ivec2(923, 124), size2_t(354, 720), size2_t(361, 914)));
    test_vec2(dvec2(586.40443213296396152, 437.98687089715537013), ImageUpsampler::convertCoordinate(ivec2(598, 556), size2_t(354, 720), size2_t(361, 914)));
    test_vec2(dvec2(426.56509695290861828, 610.50328227571117168), ImageUpsampler::convertCoordinate(ivec2(435, 775), size2_t(354, 720), size2_t(361, 914)));
    test_vec2(dvec2(294.24324324324322788, 187.03709198813058379), ImageUpsampler::convertCoordinate(ivec2(955, 783), size2_t(57, 161), size2_t(185, 674)));
    test_vec2(dvec2(244.63783783783782155, 184.88724035608308327), ImageUpsampler::convertCoordinate(ivec2(794, 774), size2_t(57, 161), size2_t(185, 674)));
    test_vec2(dvec2(90.275675675675671528, 191.57566765578633294), ImageUpsampler::convertCoordinate(ivec2(293, 802), size2_t(57, 161), size2_t(185, 674)));
    test_vec2(dvec2(119.23783783783783008, 13.615727002967359383), ImageUpsampler::convertCoordinate(ivec2(387, 57), size2_t(57, 161), size2_t(185, 674)));
    test_vec2(dvec2(8.3189189189189196583, 77.155786350148375163), ImageUpsampler::convertCoordinate(ivec2(27, 323), size2_t(57, 161), size2_t(185, 674)));
    test_vec2(dvec2(136.49189189189189619, 184.40949554896141649), ImageUpsampler::convertCoordinate(ivec2(443, 772), size2_t(57, 161), size2_t(185, 674)));
    test_vec2(dvec2(132.79459459459459936, 61.151335311572701414), ImageUpsampler::convertCoordinate(ivec2(431, 256), size2_t(57, 161), size2_t(185, 674)));
    test_vec2(dvec2(138.64864864864864558, 161.23887240356086181), ImageUpsampler::convertCoordinate(ivec2(450, 675), size2_t(57, 161), size2_t(185, 674)));
    test_vec2(dvec2(99.518918918918913619, 31.292284866468840221), ImageUpsampler::convertCoordinate(ivec2(323, 131), size2_t(57, 161), size2_t(185, 674)));
    test_vec2(dvec2(248.02702702702706006, 78.111275964391694515), ImageUpsampler::convertCoordinate(ivec2(805, 327), size2_t(57, 161), size2_t(185, 674)));
    test_vec2(dvec2(631.72399150743103746, 344.2929936305732781), ImageUpsampler::convertCoordinate(ivec2(742, 693), size2_t(401, 78), size2_t(471, 157)));
    test_vec2(dvec2(819.87898089171983429, 336.3439490445859974), ImageUpsampler::convertCoordinate(ivec2(963, 677), size2_t(401, 78), size2_t(471, 157)));
    test_vec2(dvec2(816.47346072186849142, 446.14012738853506335), ImageUpsampler::convertCoordinate(ivec2(959, 898), size2_t(401, 78), size2_t(471, 157)));
    test_vec2(dvec2(137.92356687898089262, 315.4777070063694282), ImageUpsampler::convertCoordinate(ivec2(162, 635), size2_t(401, 78), size2_t(471, 157)));
    test_vec2(dvec2(110.67940552016985123, 67.070063694267517462), ImageUpsampler::convertCoordinate(ivec2(130, 135), size2_t(401, 78), size2_t(471, 157)));
    test_vec2(dvec2(189.00636942675160412, 310.50955414012736355), ImageUpsampler::convertCoordinate(ivec2(222, 625), size2_t(401, 78), size2_t(471, 157)));
    test_vec2(dvec2(457.19108280254778265, 283.68152866242036225), ImageUpsampler::convertCoordinate(ivec2(537, 571), size2_t(401, 78), size2_t(471, 157)));
    test_vec2(dvec2(656.41401273885355749, 250.39490445859874512), ImageUpsampler::convertCoordinate(ivec2(771, 504), size2_t(401, 78), size2_t(471, 157)));
    test_vec2(dvec2(320.11889596602975416, 19.375796178343950515), ImageUpsampler::convertCoordinate(ivec2(376, 39), size2_t(401, 78), size2_t(471, 157)));
    test_vec2(dvec2(733.88959660297246046, 134.63694267515924707), ImageUpsampler::convertCoordinate(ivec2(862, 271), size2_t(401, 78), size2_t(471, 157)));
    test_vec2(dvec2(276.53240740740739056, 11.023504273504272533), ImageUpsampler::convertCoordinate(ivec2(742, 77), size2_t(161, 134), size2_t(432, 936)));
    test_vec2(dvec2(257.89814814814815236, 15.032051282051282826), ImageUpsampler::convertCoordinate(ivec2(692, 105), size2_t(161, 134), size2_t(432, 936)));
    test_vec2(dvec2(268.70601851851853326, 114.6730769230769198), ImageUpsampler::convertCoordinate(ivec2(721, 801), size2_t(161, 134), size2_t(432, 936)));
    test_vec2(dvec2(100.25231481481482376, 97.207264957264953864), ImageUpsampler::convertCoordinate(ivec2(269, 679), size2_t(161, 134), size2_t(432, 936)));
    test_vec2(dvec2(181.125, 108.6602564102564088), ImageUpsampler::convertCoordinate(ivec2(486, 759), size2_t(161, 134), size2_t(432, 936)));
    test_vec2(dvec2(218.02083333333334281, 92.626068376068374732), ImageUpsampler::convertCoordinate(ivec2(585, 647), size2_t(161, 134), size2_t(432, 936)));
    test_vec2(dvec2(307.46527777777777146, 54.974358974358970897), ImageUpsampler::convertCoordinate(ivec2(825, 384), size2_t(161, 134), size2_t(432, 936)));
    test_vec2(dvec2(187.83333333333334281, 112.38247863247863734), ImageUpsampler::convertCoordinate(ivec2(504, 785), size2_t(161, 134), size2_t(432, 936)));
    test_vec2(dvec2(200.13194444444445708, 60.557692307692306599), ImageUpsampler::convertCoordinate(ivec2(537, 423), size2_t(161, 134), size2_t(432, 936)));
    test_vec2(dvec2(256.78009259259260944, 123.262820512820511), ImageUpsampler::convertCoordinate(ivec2(689, 861), size2_t(161, 134), size2_t(432, 936)));
    test_vec2(dvec2(58.641509433962262676, 358.94252873563220874), ImageUpsampler::convertCoordinate(ivec2(74, 633), size2_t(42, 444), size2_t(53, 783)));
    test_vec2(dvec2(724.30188679245270578, 92.429118773946356669), ImageUpsampler::convertCoordinate(ivec2(914, 163), size2_t(42, 444), size2_t(53, 783)));
    test_vec2(dvec2(576.90566037735845839, 528.49042145593864461), ImageUpsampler::convertCoordinate(ivec2(728, 932), size2_t(42, 444), size2_t(53, 783)));
    test_vec2(dvec2(240.90566037735848681, 356.10727969348658917), ImageUpsampler::convertCoordinate(ivec2(304, 628), size2_t(42, 444), size2_t(53, 783)));
    test_vec2(dvec2(114.1132075471698073, 275.58620689655174374), ImageUpsampler::convertCoordinate(ivec2(144, 486), size2_t(42, 444), size2_t(53, 783)));
    test_vec2(dvec2(164.03773584905658822, 315.84674329501916645), ImageUpsampler::convertCoordinate(ivec2(207, 557), size2_t(42, 444), size2_t(53, 783)));
    test_vec2(dvec2(633.96226415094338336, 178.62068965517241281), ImageUpsampler::convertCoordinate(ivec2(800, 315), size2_t(42, 444), size2_t(53, 783)));
    test_vec2(dvec2(544.41509433962266939, 532.4597701149424438), ImageUpsampler::convertCoordinate(ivec2(687, 939), size2_t(42, 444), size2_t(53, 783)));
    test_vec2(dvec2(234.5660377358490507, 154.80459770114941875), ImageUpsampler::convertCoordinate(ivec2(296, 273), size2_t(42, 444), size2_t(53, 783)));
    test_vec2(dvec2(224.26415094339623124, 526.78927203065143203), ImageUpsampler::convertCoordinate(ivec2(283, 929), size2_t(42, 444), size2_t(53, 783)));
    test_vec2(dvec2(106.11202185792349439, 111.75), ImageUpsampler::convertCoordinate(ivec2(547, 298), size2_t(71, 12), size2_t(366, 32)));
    test_vec2(dvec2(18.81693989071038331, 195), ImageUpsampler::convertCoordinate(ivec2(97, 520), size2_t(71, 12), size2_t(366, 32)));
    test_vec2(dvec2(63.628415300546450339, 257.625), ImageUpsampler::convertCoordinate(ivec2(328, 687), size2_t(71, 12), size2_t(366, 32)));
    test_vec2(dvec2(81.281420765027320385, 215.25), ImageUpsampler::convertCoordinate(ivec2(419, 574), size2_t(71, 12), size2_t(366, 32)));
    test_vec2(dvec2(153.83333333333331439, 259.5), ImageUpsampler::convertCoordinate(ivec2(793, 692), size2_t(71, 12), size2_t(366, 32)));
    test_vec2(dvec2(7.7595628415300543779, 274.125), ImageUpsampler::convertCoordinate(ivec2(40, 731), size2_t(71, 12), size2_t(366, 32)));
    test_vec2(dvec2(64.210382513661201642, 3.375), ImageUpsampler::convertCoordinate(ivec2(331, 9), size2_t(71, 12), size2_t(366, 32)));
    test_vec2(dvec2(105.72404371584698879, 42), ImageUpsampler::convertCoordinate(ivec2(545, 112), size2_t(71, 12), size2_t(366, 32)));
    test_vec2(dvec2(76.043715846994544449, 207.75), ImageUpsampler::convertCoordinate(ivec2(392, 554), size2_t(71, 12), size2_t(366, 32)));
    test_vec2(dvec2(141.61202185792350861, 91.875), ImageUpsampler::convertCoordinate(ivec2(730, 245), size2_t(71, 12), size2_t(366, 32)));
}

}  // namespace inviwo