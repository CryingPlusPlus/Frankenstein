#include <iostream>
#include <memory>
#include <algorithm>
#include <array>

template<size_t ROW, size_t COL>
class Matrix
{
    private:
        std::array<float, ROW * COL> container;

    public:
        Matrix(std::array<float, ROW * COL> init)
        {
            container = init;
        }
        Matrix()
        {
            std::transform(container.begin(), container.end(), container.begin(), [](float x){ return 0; });
        }
        ~Matrix(){}

        auto operator () (int a, int b)
        {
            return container.begin() + a * COL + b;
        }
        
        template<size_t U>
        auto operator * (Matrix<COL, U> rhs)
        {
            Matrix<ROW, U> end{};
            for(int r = 0; r < ROW; ++r)
            {
                for(int u = 0; u < U; ++u)
                {
                    for(int c = 0; c < COL; ++c)
                        *end(r, u) += container[r * COL + c] * *rhs(c, u);
                }
            }
            return end;
        }

        auto operator * (float num)
        {
            std::array<float, ROW * COL> end = container;
            std::transform(end.begin(), end.end(), end.begin(), [num](float el){ return el * num; });
            return Matrix<ROW, COL>{std::move(end)};
        }

        auto operator + (Matrix<ROW, COL> rhs)
        {
            Matrix<ROW, COL> end{container};
            for(int i = 0; i < ROW; ++i)
            {
                for(int  j = 0; j < COL; ++j)
                {
                    *end(i, j) += *rhs(i, j);
                }
            }
            return end;
        }

        auto operator - (Matrix<ROW, COL> rhs)
        {
            Matrix<ROW, COL> end{container};
            for(int i = 0; i < ROW; ++i)
            {
                for(int  j = 0; j < COL; ++j)
                {
                    *end(i, j) -= *rhs(i, j);
                }
            }
            return end;
        }

        template<size_t X, size_t Y>
        auto operator * (Matrix<X, Y> rhs)
        {
            Matrix<ROW, Y> end{};
            throw std::invalid_argument("shape error");
            return end;
        }
};

int main()
{
    return 0;
}
