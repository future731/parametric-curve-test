#include "3rdparty/eiquadprog_test.hpp"
#include <limits>
#include <iostream>


/*
 * minimize 1/2 x^T G x + g0^T x
 * subject to CE^T x + ce0 = 0
 * subject to CI^T x + ci0 >= 0
 */
int main()
{
    Eigen::MatrixXd G(14, 14);
    G <<
1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,1;
        /*
1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,1.1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1.2,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1.3,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,1.4,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,1.5,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1.6,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1.7,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,1.8,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1.9,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,2,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,2.1,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,2.2,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,2.3;
*/
    Eigen::VectorXd g0(14);
    g0 << 0,0,0,0,0,0,0,0,0,0,0,0,0,0;
    Eigen::MatrixXd CE(3, 14);
    CE <<
0.0047059,0.173799,0.544201,0.263379,0.0139154,1.22444e-07,0,0,0,0,0,0,0,0,
-0.237405,-3.38082,-0.961173,4.01446,0.564878,5.10183e-05,0,0,0,0,0,0,0,0,
0,0,0,0,0.000260417,0.0617188,0.438021,0.438021,0.0617188,0.000260417,0,0,0,0;
    Eigen::VectorXd ce0(3);
    ce0 <<
-0,-0,0.000188959;
    //Eigen::MatrixXd CI(54, 14);
    //Eigen::MatrixXd CI(26, 14);
    Eigen::MatrixXd CI(0, 14);
    //CI <<
        /*
1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,1,
-1,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
-0,-1,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
-0,-0,-1,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
-0,-0,-0,-1,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
-0,-0,-0,-0,-1,-0,-0,-0,-0,-0,-0,-0,-0,-0,
-0,-0,-0,-0,-0,-1,-0,-0,-0,-0,-0,-0,-0,-0,
-0,-0,-0,-0,-0,-0,-1,-0,-0,-0,-0,-0,-0,-0,
-0,-0,-0,-0,-0,-0,-0,-1,-0,-0,-0,-0,-0,-0,
-0,-0,-0,-0,-0,-0,-0,-0,-1,-0,-0,-0,-0,-0,
-0,-0,-0,-0,-0,-0,-0,-0,-0,-1,-0,-0,-0,-0,
-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-1,-0,-0,-0,
-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-1,-0,-0,
-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-1,-0,
-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-1,
9,-9,0,0,0,0,0,0,0,0,0,0,0,0,
0,9,-9,0,0,0,0,0,0,0,0,0,0,0,
0,0,9,-9,0,0,0,0,0,0,0,0,0,0,
0,0,0,9,-9,0,0,0,0,0,0,0,0,0,
0,0,0,0,9,-9,0,0,0,0,0,0,0,0,
0,0,0,0,0,9,-9,0,0,0,0,0,0,0,
0,0,0,0,0,0,9,-9,0,0,0,0,0,0,
0,0,0,0,0,0,0,9,-9,0,0,0,0,0,
0,0,0,0,0,0,0,0,9,-9,0,0,0,0,
0,0,0,0,0,0,0,0,0,9,-9,0,0,0,
0,0,0,0,0,0,0,0,0,0,9,-9,0,0,
0,0,0,0,0,0,0,0,0,0,0,9,-9,0,
0,0,0,0,0,0,0,0,0,0,0,0,9,-9,
-9,9,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
-0,-9,9,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
-0,-0,-9,9,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,
-0,-0,-0,-9,9,-0,-0,-0,-0,-0,-0,-0,-0,-0,
-0,-0,-0,-0,-9,9,-0,-0,-0,-0,-0,-0,-0,-0,
-0,-0,-0,-0,-0,-9,9,-0,-0,-0,-0,-0,-0,-0,
-0,-0,-0,-0,-0,-0,-9,9,-0,-0,-0,-0,-0,-0,
-0,-0,-0,-0,-0,-0,-0,-9,9,-0,-0,-0,-0,-0,
-0,-0,-0,-0,-0,-0,-0,-0,-9,9,-0,-0,-0,-0,
-0,-0,-0,-0,-0,-0,-0,-0,-0,-9,9,-0,-0,-0,
-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-9,9,-0,-0,
-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-9,9,-0,
-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-0,-9,9;
*/
    //Eigen::VectorXd ci0(54);
    //Eigen::VectorXd ci0(26);
    Eigen::VectorXd ci0(0);
    //ci0 <<
//1.54856,-0,0.301663,0.124446,0.269502,0.414281,0.355137,0.560598,0.820631,0.934842,0.921771,0.927089,0.925075,0.927349,
//1.6887,3.23726,2.9356,3.11281,2.96776,2.82298,2.88212,2.67666,2.41663,2.30242,2.31549,2.31017,2.31218,2.30991,
//-1.77346,-9.93708,6.71497,2.40505,5.3055,5.30302,3.4677,5.84915,6.3403,5.02789,3.88236,4.04786,3.98187,
//9.77346,17.9371,1.28503,5.59495,2.6945,2.69698,4.5323,2.15085,1.6597,2.97211,4.11764,3.95214,4.01813;
    Eigen::VectorXd ans(14);
    std::cout << std::endl;
    std::cout << "opt: " << Eigen::solve_quadprog(G, g0, CE.transpose(), ce0, CI.transpose(), ci0, ans) << std::endl;
    std::cout << ans.transpose() << std::endl;
    Eigen::MatrixXd CI1(13, 14);
    CI1 <<
9,-9,0,0,0,0,0,0,0,0,0,0,0,0,
0,9,-9,0,0,0,0,0,0,0,0,0,0,0,
0,0,9,-9,0,0,0,0,0,0,0,0,0,0,
0,0,0,9,-9,0,0,0,0,0,0,0,0,0,
0,0,0,0,9,-9,0,0,0,0,0,0,0,0,
0,0,0,0,0,9,-9,0,0,0,0,0,0,0,
0,0,0,0,0,0,9,-9,0,0,0,0,0,0,
0,0,0,0,0,0,0,9,-9,0,0,0,0,0,
0,0,0,0,0,0,0,0,9,-9,0,0,0,0,
0,0,0,0,0,0,0,0,0,9,-9,0,0,0,
0,0,0,0,0,0,0,0,0,0,9,-9,0,0,
0,0,0,0,0,0,0,0,0,0,0,9,-9,0,
0,0,0,0,0,0,0,0,0,0,0,0,9,-9;
    Eigen::VectorXd ci1(13);
ci1 << -1.77346,-9.93708,6.71497,2.40505,5.3055,5.30302,3.4677,5.84915,6.3403,5.02789,3.88236,4.04786,3.98187;
    std::cout << "CI1*ans: " << (CI1 * ans).transpose() << std::endl;
    std::cout << "ci1: " << ci1.transpose() << std::endl;
  return 0;
}
