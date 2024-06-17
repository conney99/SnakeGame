# SnakeGame 프로젝트 소개
<h2>-c++ 프로그래밍-</h2>   

목표 : C++ 프로그래밍 언어로 ncurses 라이브러리를 사용하여 Snake Game을 구현한다.


<h2>게임 조작</h2>  

방향키를 직접 지정하여  **Snake**를 상하좌우로 조작한다.  

<h3>item</h3> 

```
 Growth Item - 몸 길이 1증가
 Poison Item - 몸 길이 1감소
```  
 아이템은 Snake가 있지 않은 임의의 위치에 출현한다.
 출현 후 일정시간이 지나면 사라지고 다른 위치가 나타난다.
  

<h3>gate</h3> 
게이트는 임의의 위치의 벽에서 생성된다.  
게이트에 snake가 진입하면 연결된 다른 gate로 진출한다.  

<h3>score board</h3> 
growth, poison, gatee등의 점수들을 토대로 미션 달성 여부를 확인한다.
일정 점수 이상이 되면 다음 스테이지로 넘어간다.  


<h3>gameover</h3> 

snake 가 진행방향의 반대방향으로 이동한다.  
snake 가 자신의 몸에 부딪힌다.  
snake 가 벽에 부딪힌다.  
snake 의 몸 길이가 3보다 작아진다.  

<h2>-file별 내용 정리-</h2>   
https://conney99.notion.site/Snake-game-9a6e3fb7fca04267aa7254cbc8d7bd36?pvs=4


