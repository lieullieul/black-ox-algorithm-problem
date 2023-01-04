#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 굉장히 무식하게 해결
//
int solution(int n, int** wires, size_t wires_rows, size_t wires_cols)
{
    int tree1[100];
    int tree2[100];
    int tmp[100][2];
    int tree1Size = 100;
    int tree2Size = 100;
    int min = 100;

    // wires[i] 전선을 끊었을 때 생기는 두 트리의 사이즈 비교
    // 두 트리의 사이즈 차이가 가장 작은 케이스 찾기
    for (size_t i = 0; i < wires_rows; i++)
    {
        // 트리 버퍼 초기화, 초기값 설정
        memset(tree1, 0, sizeof(int) * tree1Size);
        memset(tree2, 0, sizeof(int) * tree2Size);
        tree1[0] = wires[i][0];
        tree2[0] = wires[i][1];
        tree1Size = 1;
        tree2Size = 1;

        // wires 임시 버퍼 tmp 초기화
        for (size_t x = 0; x < wires_rows; x++)
            memcpy(tmp[x], wires[x], sizeof(int) * 2);

        // 두 트리의 합이 n보다 작은 동안 탐색
        // 트리의 노드와 연결된 모든 노드 찾아서 트리에 넣고 트리사이즈 증가시킴
        // 트리사이즈가 증가하지 않을 때까지 반복
        //  -> 연결된 모든 트리 탐색
        size_t tree1Idx = 0;
        size_t tree2Idx = 0;
        while (tree1Size + tree2Size < n)
        {
            while (tree1Idx < tree1Size)
            {
                for (size_t j = 0; j < wires_rows; j++)
                {
                    if (i == j)
                        continue;
                    if (tree1[tree1Idx] == tmp[j][0])
                    {
                        tree1[tree1Size] = tmp[j][1];
                        tmp[j][0] = 0;
                        tmp[j][1] = 0;
                        tree1Size++;
                    }
                    if (tree1[tree1Idx] == tmp[j][1])
                    {
                        tree1[tree1Size] = tmp[j][0];
                        tmp[j][0] = 0;
                        tmp[j][1] = 0;
                        tree1Size++;
                    }
                }
                tree1Idx++;
            }
            while (tree2Idx < tree2Size)
            {
                for (size_t j = 0; j < wires_rows; j++)
                {
                    if (i == j)
                        continue;
                    if (tree2[tree2Idx] == tmp[j][0])
                    {
                        tree2[tree2Size] = tmp[j][1];
                        tmp[j][0] = 0;
                        tmp[j][1] = 0;
                        tree2Size++;
                    }
                    if (tree2[tree2Idx] == tmp[j][1])
                    {
                        tree2[tree2Size] = tmp[j][0];
                        tmp[j][0] = 0;
                        tmp[j][1] = 0;
                        tree2Size++;
                    }
                }
                tree2Idx++;
            }
        }
        // 두 트리의 차 중 최소값 저장
        if (abs(tree1Size - tree2Size) < min)
            min = abs(tree1Size - tree2Size);
    }
    return min;
}
