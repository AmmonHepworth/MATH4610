#ifndef MATRIX_H
#define MATRIX_H

#include<vector>
#include<cmath>
#include<stack>
#include<iostream>
#include <string>
#include <array>
#include <cstdlib>
#include "../maceps/maceps.h"

template<typename T, std::size_t M, std::size_t N>
using Matrix = std::array<std::array<T,N>,M>;

  template<typename T, std::size_t M, std::size_t N>
Matrix<T,M,N> genZeros()
{
  Matrix<T,M,N> mat;
  for(int i=0; i<M; ++i)
  {
    for(int j=0; j<N; ++j)
      mat[i][j] = 0;
  }
  return mat;
}

  template<typename T, std::size_t M, std::size_t N>
Matrix<T,M,N> genIdentity()
{
  Matrix<T,M,N> mat = genZeros<T,M,N>();
  for(int i=0; i<M; ++i)
  {
    mat[i][i] = (T)1;
  }
  return mat;
}

  template<typename T, std::size_t M, std::size_t N>
Matrix<T,M,N> genRandoms()
{
  std::srand(time(NULL));
  Matrix<T,M,N> mat = genZeros<T,M,N>();
  for(int i=0; i<M; ++i)
  {
    for(int j=0; j<N; ++j)
    {
      mat[i][j] = (T)(std::rand() % 10);
    }
  }
  return mat;
}

  template <typename T, size_t M>
bool allClose(Matrix<T,M,1> mat1, Matrix<T,M,1> mat2)
{
  for(int i=0; i<M; ++i)
  {
    if(std::abs(mat1[i][0]-mat2[i][0]) >= getMacEps<double>()) return false;
  }
  return true;
}

  template <typename T, size_t M>
double dot(Matrix<T,M,1> mat1, Matrix<T,M,1> mat2)
{
  double sum=0;
  for(int i=0; i<M; ++i)
  {
    sum += mat1[i][0]*mat2[i][0];
  }
  return sum;
}

  template <typename T>
Matrix<T,3,1> cross(Matrix<T,3,1> mat1, Matrix<T,3,1> mat2)
{
  Matrix<T,3,1> res = {{ {mat1[1][0]*mat2[2][0] - mat1[2][0]*mat2[1][0]},
    {mat1[2][0]*mat2[0][0] - mat1[0][0]*mat2[2][0]},
    {mat1[0][0]*mat2[1][0] - mat1[1][0]*mat2[0][0]}  }};
  return res;
}

  template <typename T, size_t M, size_t N>
Matrix<T,N,M> transpose(Matrix<T,M,N> mat)
{
  Matrix<T,N,M> ret;
  for(int i=0; i<M; ++i)
  {
    for(int j=0; j<N; ++j)
    {
      ret[j][i] = mat[i][j];
    }
  }
  return ret;
}

  template <typename T, size_t M>
T trace(Matrix<T,M,M> mat)
{
  T ret = 0;
  for(int i=0; i<M; ++i)
  {
    ret += mat[i][i];
  }
  return ret;
}

  template<typename T, std::size_t M, std::size_t N>
Matrix<double,M,1> forwardSubstitute(Matrix<T,M,N> L, Matrix<double,M,1> sol)
{
  Matrix<double,M,1> x;
  x[0][0] = sol[0][0];
  for(int i=0; i<M; ++i)
  {
    double sum = 0;
    for(int j=0; j<i; ++j)
    {
      sum += L[i][j]*x[j][0];
    }
    x[i][0] = (sol[i][0] - sum)/ L[i][i];
  }
  return x;
}

  template<typename T, std::size_t M, std::size_t N>
Matrix<double,M,1> backSubstitute(Matrix<T,M,N> U, Matrix<double,M,1> b)
{
  Matrix<double,M,1> x = genZeros<double,M,1>();

  for(int i=(int)M-1;i>=0;--i)
  {
    double sum = 0;
    for(int j=(int)i+1; j<(int)M; ++j)
    {
      sum += U[i][j]*x[j][0];
    }
    x[i][0] = (b[i][0] - sum) / U[i][i];
  }
  return x;
}

  template<typename T, typename T2, typename R = decltype(T()*T2()), std::size_t M, std::size_t N, std::size_t P, std::size_t Q>
Matrix<R,M*P,N*Q> kronecker(Matrix<T,M,N> lh, Matrix<T2,P,Q> rh)
{
  Matrix<R,M*P,N*Q> ret;
  for(int i=0; i<M*P; ++i)
  {
    for(int j=0; j<N*Q; ++j)
    {
      ret[i][j] = lh[i/N][j/M] * rh[i%P][j%Q];
    }
  }
  return ret;
}


  template<typename T, std::size_t M, std::size_t N>
Matrix<T,M-1,N> withoutRow(Matrix<T,M,N> mat, int row)
{
  if(row >= M) std::cout << "removing a row further than exists" << std::endl;
  Matrix<T,M-1,N> ret;
  for(int i=0; i<M-1; ++i)
  {
    if(i < row)
      ret[i] = mat[i];
    else 
      ret[i] = mat[i+1];
  }
  return ret;
}

  template<typename T, std::size_t M, std::size_t N>
Matrix<T,M,N-1> withoutCol(Matrix<T,M,N> mat, int col)
{
  if(col >= N) std::cout << "removing a col further than exists" << std::endl;
  Matrix<T,M,N-1> ret;
  for(int i=0; i<M; ++i)
  {
    for(int j=0; j<N-1; ++j)
    {
      if(j < col)
        ret[i][j] = mat[i][j];
      else
        ret[i][j] = mat[i][j+1];
    }
  }
  return ret;
}

  template<typename T>
std::vector<std::vector<T> > withoutRow(std::vector<std::vector<T> > mat, int row)
{
  if(row >= mat.size()) std::cout << "removing a row further than exists" << std::endl;
  std::vector<std::vector<T> >ret;
  for(int i=0; i<mat.size()-1; ++i)
  {
    if(i < row)
      ret.push_back(mat[i]);
    else 
      ret.push_back(mat[i+1]);
  }
  return ret;
}

  template<typename T>
std::vector<std::vector<T> > withoutCol(std::vector<std::vector<T> > mat, int col)
{
  if(col >= mat.size()) std::cout << "removing a col further than exists" << std::endl;
  std::vector<std::vector<T> > ret(mat.size());
  for(int i=0; i<mat.size(); ++i)
  {
    for(int j=0; j<mat[1].size()-1; ++j)
    {
      if(j < col)
        ret[i].push_back(mat[i][j]);
      else
        ret[i].push_back(mat[i][j+1]);
    }
  }
  return ret;
}

template<typename T>
double _det(std::vector<std::vector<T> > mat)
{
  T det = 0;
  if(mat.size() == 2)
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

  std::vector<std::vector<T>> newMat = mat;
  for(int i=0; i<mat.size(); ++i)
  {
    std::vector<std::vector<T> > lessCol = withoutCol(mat,i);
    std::vector<std::vector<T> > lessRow = withoutRow(lessCol,0);
    auto detStep = mat[0][i] * _det(lessRow);
    det += (i%2==0) ? detStep : -detStep;
  }
}

template<typename T, std::size_t M>
double determinant(Matrix<T,M,M> mat)
{
  std::vector<std::vector<T> > newMat(M);
  for(int i=0; i<M; ++i)
  {
    newMat[i] = std::vector<T>(mat[i].begin(),mat[i].end());
  }

  return _det(newMat);
}

  template<typename L, typename R, typename T = decltype(L()+R()), std::size_t M, std::size_t N >
Matrix<T,M,N> operator+(const Matrix<L,M,N> lh, const Matrix<R,M,N> rh)
{
  //TODO: Replace with M
  Matrix<T,M,N> ret = lh;
  for(int i=0; i<lh.size(); ++i)
  {
    //TODO: Replace with N
    if(lh[i].size() != rh[i].size()) return lh;
    for(int j=0; j<lh[i].size(); ++j)
    {
      ret[i][j] += rh[i][j];
    }
  }
  return ret;
}

  template<typename L, typename R, typename T = decltype(L()+R()), std::size_t M, std::size_t N >
Matrix<T,M,N> operator-(Matrix<L,M,N> lh, Matrix<R,M,N> rh)
{
  if(lh.size() != rh.size()) return lh;
  for(int i=0; i<lh.size(); ++i)
  {
    if(lh[i].size() != rh[i].size()) return lh;
    for(int j=0; j<lh[i].size(); ++j)
    {
      lh[i][j] -= rh[i][j];
    }
  }
  return lh;
}


  template<typename L, typename R, typename T = decltype(L()*R()), std::size_t M, std::size_t N, std::size_t O >
Matrix<T,M,O> operator*(const Matrix<L,M,N> lh, const Matrix<R,N,O> rh)
{
  Matrix<T,M,O> temp = genZeros<T,M,O>();
  for(int i=0; i<M; ++i)
  {
    for(int j=0; j<O; ++j)
    {
      for(int k=0; k<N; ++k)
      {
        temp[i][j] += lh[i][k] * rh[k][j];
      }
    }
  }
  return temp;
}

  template<typename L, typename R, typename T = decltype(L()*R()), std::size_t M, std::size_t N>
Matrix<T,M,N> operator*(const Matrix<L,M,N> lh, const R rh)
{
  Matrix<T,M,N> temp = genZeros<T,M,N>();
  for(int i=0; i<M; ++i)
  {
    for(int j=0; j<N; ++j)
    {
      temp[i][j] = lh[i][j] * rh;
    }
  }
  return temp;
}

  template<typename L, typename R, typename T = decltype(L()*R()), std::size_t M, std::size_t N>
Matrix<T,M,N> operator*(const R rh, const Matrix<L,M,N> lh)
{
  Matrix<T,M,N> temp = genZeros<T,M,N>();
  for(int i=0; i<M; ++i)
  {
    for(int j=0; j<N; ++j)
    {
      temp[i][j] = lh[i][j] * rh;
    }
  }
  return temp;
}

  template<typename L, typename R, typename T = decltype(L()*R()), std::size_t M, std::size_t N>
Matrix<T,M,N> operator/(const Matrix<L,M,N> lh, const R rh)
{
  Matrix<T,M,N> temp = genZeros<T,M,N>();
  for(int i=0; i<M; ++i)
  {
    for(int j=0; j<N; ++j)
    {
      temp[i][j] = lh[i][j] / rh;
    }
  }
  return temp;
}

  template<typename T, std::size_t M, std::size_t N>
std::ostream& operator<<(std::ostream& strm, Matrix<T,M,N> const & rh)
{
  for(int i=0;i<rh.size();++i)
  {
    strm << "| ";
    for(int j=0;j<rh[i].size();++j)
    {
      strm << rh[i][j] << " ";
    }
    strm << "|" << std::endl;
  }
  return strm;
}
#endif
