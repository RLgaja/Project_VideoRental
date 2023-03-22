# Project_VideoRental

고객이 영화를 대여하고, 영수증을 발급하는 프로그램이며, 아래의 기능을 담고있습니다.

  - 입력받은 영화를 원하는 날짜만큼 대여가능합니다.
  - 고객이 대여할 영화는 영화제목과 장르를 입력받아 작성됩니다.
  - 대여 시 대여금, 포인트가 영화 종류 마다 다르게 책정됩니다.
  - 출력되는 영수증에는 영화별 가격, 합산가격, 획득한 포인트가 보여집니다.

<문제1>
  1> 새로운 영화장르(EXAMPLE_GENRE)를 하나 추가해 주세요.
  2> 현재 영수증 하단에 새로운 출력형식의 영수증을 출력해주세요.
  * 출력형식 : (장르 제목 대여기간 가격)
  
<문제2>
  문제 1을 수행하신뒤, 
    1> 코드의 문제점을 자유롭게 기술하신뒤 개선방향을 제시해주세요.

      [문제점] 
      코드의 가독성이 떨어져 기능별로 함수화 작업이 필요하고, 이름이 모호한 함수나 변수에 대해, 이름 변경이 필요함

      [문제점 개선을 위한 구현 목록]
      1) 코드 가독성을 위해 자동 줄바꿈 진행

      2) 사용중인 함수를 의미있는 이름으로 변경
      : Customer.h/.cpp 내 "getName" 함수를 getCostomerName으로 변경하여 고객의 이름을 얻기 위한 함수임을 표시

      3) 기능별로 함수화 작업 진행
        - Customer.h/.cpp 내 "getRentalFee" 함수 추가
          - 영화 종류와 대여 일수에 따른 대여금 계산 관련 코드를 "getRentalFee" 함수에 추가
        - Customer.h/.cpp 내 "getRenterPoints" 함수 추가
          - 영화 종류와 대여 일수에 따른 포인트 계산 관련 코드를 "getRenterPoints" 함수에 추가
        - Customer.h/.cpp 내 "printStatement" 함수 추가
          - 영수증 출력 관련 코드를 "printStatement" 함수에 추가
        - 영수증 출력 관련 내용을 저장할 수 있도록 구조체 
          - 영수증 출력 관련(장르, 영화제목, 대여기간, 가격, 고객의 총 대여가격, 총회득 포인트) 변수를 저장할 수 있도록  "RentalLog" 구조체 추가

    2> 문제점 개선을 위한 구현 목록을 바탕으로 구현함


