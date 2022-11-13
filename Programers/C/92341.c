#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
* struct
*/
typedef struct stData // 주차장 이용 내역 정보
{
    int use;    // 실 이용 시간
    int lastIn; // 마지막 입차 시간
    bool out;   // 출차 여부
}t_CarInfo;

typedef struct stNode // 이용 차량 리스트 노드
{
    int number; // 차 번호
    int fee;    // 이용 요금
    struct stNode* pre;
    struct stNode* next;
}t_List;

/*
* global
*/
t_CarInfo g_cars[10000]; // 인덱스 -> 차 번호

/*
* list util func
*/
// 마지막 노드 리턴
t_List* getListBack(t_List* lst)
{
    t_List* ret;

    ret = lst;
    while (ret->next)
        ret = ret->next;
    return ret;
}

// 첫 노드 리턴
t_List* getListFront(t_List* lst)
{
    t_List* ret;

    ret = lst;
    while (ret->pre)
        ret = ret->pre;
    return ret;
}

// 새로운 노드 추가
// 차량 번호 오름차순으로 삽입
bool addCarNumber(t_List** lst, int carNumber)
{
    t_List* tmp;
    t_List* cur;

    tmp = (t_List*)malloc(sizeof(t_List));
    if (!tmp)
        return false;
    tmp->number = carNumber;
    tmp->pre = NULL;
    tmp->next = NULL;
    if (*lst)
    {
        cur = getListFront(*lst);
        while (cur)
        {
            if (carNumber < cur->number)
            {
                if (cur->pre)
                    cur->pre->next = tmp;
                tmp->pre = cur->pre;
                cur->pre = tmp;
                tmp->next = cur;
                *lst = getListFront(tmp);
                return true;
            }
            cur = cur->next;
        }
        cur = getListBack(*lst);
        cur->next = tmp;
        tmp->pre = cur;
        *lst = getListFront(tmp);
    }
    else
        *lst = tmp;
    return true;
}

// 리스트 노드 갯수 리턴
size_t getListSize(t_List *lst)
{
    t_List* cur;
    size_t ret;

    ret = 0;
    cur = lst;
    while (cur)
    {
        cur = cur->next;
        ret++;
    }
    return ret;
}

// 리스트 할당 해제
void freeList(t_List* lst)
{
    t_List* cur;
    t_List* tmp;

    cur = lst;
    while (cur)
    {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

/*
* procedure
*/
// 입차
// 입차 시간, 출차 상태 저장
// 첫 입차 시 노드 생성 위해 플래그 리턴
bool in(t_CarInfo* car, const char* record)
{
    bool exist = false;
    int inTime = atoi(&record[0]) * 60 + atoi(&record[3]);

    if (car->use != 0 || car->lastIn != 0)
        exist = true;
    car->out = false;
    car->lastIn = inTime;
    return exist;
}

// 출차
// 주차장 사용 시간 저장, 출차 상태 저장
void out(t_CarInfo* car, const char* record)
{
    int outTime = atoi(&record[0]) * 60 + atoi(&record[3]);

    car->use += outTime - car->lastIn;
    car->out = true;
}

// 요금 계산
int getFee(int use, const int* fees)
{
    int baseTime = fees[0];
    int base = fees[1];
    int surchargeTime = fees[2];
    int surcharge = fees[3];

    if (use < fees[0])
        return base;
    else
        return base + (int)(ceil((double)(use - baseTime)/surchargeTime)) * surcharge;
}

// 차량 별 주차장 이용시간 요금으로 환산
// records 탐색 후 출차되지 않은 차의 이용시간 계산
void timeToFee(t_CarInfo cars[], t_List* lst, const int* fees)
{
    t_List* cur;

    cur = lst;
    while (cur)
    {
        if(cars[cur->number].out == false)
            cars[cur->number].use += 1439 - cars[cur->number].lastIn;
        cur->fee = getFee(cars[cur->number].use, fees);
        cur = cur->next;
    }
}

/*
* solution
*/
int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len)
{
    int* answer;
    t_List* lstReceipt = NULL; // 각 차의 이용요금 리스트
    t_List* cur;
    int carNumber;
    size_t size;
    bool isExist = false;

    memset(g_cars, 0, sizeof(t_CarInfo) * 10000);

    // records 탐색
    // 입차
    //  -> 첫 입차 시 노드 생성
    //    -> 오름차순으로 적절한 위치에 삽입
    // 출차
    for (size_t i = 0; i < records_len; i++)
    {
        carNumber = atoi(&records[i][6]);
        isExist = false;

        if (records[i][11] == 'I')
        {
            isExist = in(&g_cars[carNumber], records[i]);
            if (isExist == false)
            {
                if (!addCarNumber(&lstReceipt, carNumber))
                {
                    freeList(lstReceipt);
                    return NULL;
                }
            }
        }
        else
            out(&g_cars[carNumber], records[i]);
    }

    // 요금 계산
    // 23:59까지 출차되지 않은 차량들
    timeToFee(g_cars, lstReceipt, fees);

    // 리턴할 정수 배열 할당
    size = getListSize(lstReceipt);
    cur = lstReceipt;
    answer = (int*)malloc(sizeof(int) * size);
    if (!answer)
    {
        freeList(lstReceipt);
        return NULL;
    }

    // 정수 배열에 이용 요금 저장
    for (size_t i = 0; i < size; i++)
    {
        memcpy(&answer[i], &(cur->fee), sizeof(int));
        cur = cur->next;
    }

    // 리스트 할당 해제
    freeList(lstReceipt);
    return answer;
}
