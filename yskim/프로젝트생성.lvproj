<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="14008000">
	<Item Name="내 컴퓨터" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">내 컴퓨터/VI 서버</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">내 컴퓨터/VI 서버</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="1day" Type="Folder">
			<Item Name="더하기.vi" Type="VI" URL="../1day/더하기.vi"/>
			<Item Name="실습1-2.vi" Type="VI" URL="../1day/실습1-2.vi"/>
			<Item Name="실습1-3 객체정렬.vi" Type="VI" URL="../1day/실습1-3 객체정렬.vi"/>
			<Item Name="실습2-1숫자형데이터삽입.vi" Type="VI" URL="../1day/실습2-1숫자형데이터삽입.vi"/>
			<Item Name="실습2-2여러숫자더하기.vi" Type="VI" URL="../1day/실습2-2여러숫자더하기.vi"/>
			<Item Name="실습2-3수식노드사용.vi" Type="VI" URL="../1day/실습2-3수식노드사용.vi"/>
			<Item Name="실습2-4텍스트링.vi" Type="VI" URL="../1day/실습2-4텍스트링.vi"/>
			<Item Name="실습2-5난수발생45.vi" Type="VI" URL="../1day/실습2-5난수발생45.vi"/>
			<Item Name="실습2-7복합불리언 연산.vi" Type="VI" URL="../1day/실습2-7복합불리언 연산.vi"/>
			<Item Name="실습2-8 문자열 함수.vi" Type="VI" URL="../1day/실습2-8 문자열 함수.vi"/>
		</Item>
		<Item Name="2day" Type="Folder">
			<Item Name="serial_com.vi" Type="VI" URL="../2day/serial_com.vi"/>
			<Item Name="시분초파일 하다맘.vi" Type="VI" URL="../2day/시분초파일 하다맘.vi"/>
			<Item Name="실습 3-1 연속적인 난수 발생.vi" Type="VI" URL="../2day/실습 3-1 연속적인 난수 발생.vi"/>
			<Item Name="실습 3-2 난수 맞추기.vi" Type="VI" URL="../2day/실습 3-2 난수 맞추기.vi"/>
			<Item Name="실습 3-3 계단식 증가 전압 만들기.vi" Type="VI" URL="../2day/실습 3-3 계단식 증가 전압 만들기.vi"/>
			<Item Name="실습 3-4 조건적 자동 인덱싱.vi" Type="VI" URL="../2day/실습 3-4 조건적 자동 인덱싱.vi"/>
			<Item Name="실습 3-5 신호 Running Average.vi" Type="VI" URL="../2day/실습 3-5 신호 Running Average.vi"/>
			<Item Name="실습 4-1 배열 만들기(컨트롤배열).vi" Type="VI" URL="../2day/실습 4-1 배열 만들기(컨트롤배열).vi"/>
			<Item Name="실습 4-2 강도 그래프 사용하기(컨트롤 2차원배열).vi" Type="VI" URL="../2day/실습 4-2 강도 그래프 사용하기(컨트롤 2차원배열).vi"/>
			<Item Name="실습 4-3 배열 인덱스 함수.vi" Type="VI" URL="../2day/실습 4-3 배열 인덱스 함수.vi"/>
		</Item>
		<Item Name="3day" Type="Folder">
			<Item Name="myButton.ctl" Type="VI" URL="/&lt;userlib&gt;/myButton.ctl"/>
			<Item Name="my글로벌.vi" Type="VI" URL="../3day/my글로벌.vi"/>
			<Item Name="review.vi" Type="VI" URL="../3day/review.vi"/>
			<Item Name="serial 클러스터.vi" Type="VI" URL="../3day/serial 클러스터.vi"/>
			<Item Name="배열에 값을 순차적으로 입력하기.vi" Type="VI" URL="../3day/배열에 값을 순차적으로 입력하기.vi"/>
			<Item Name="실습 5-1 클러스터 풀기와 묶기.vi" Type="VI" URL="../3day/실습 5-1 클러스터 풀기와 묶기.vi"/>
			<Item Name="실습 5-4 열거형 케이스 선택자.vi" Type="VI" URL="../3day/실습 5-4 열거형 케이스 선택자.vi"/>
			<Item Name="실습 6-1 이벤트 구조 사용.vi" Type="VI" URL="../3day/실습 6-1 이벤트 구조 사용.vi"/>
			<Item Name="실습 6-2 신호시뮬레이션(이벤트).vi" Type="VI" URL="../3day/실습 6-2 신호시뮬레이션(이벤트).vi"/>
			<Item Name="실습 7-2 사용자 컨트롤 만들기.vi" Type="VI" URL="../3day/실습 7-2 사용자 컨트롤 만들기.vi"/>
			<Item Name="실습 8-2 글로벌 변수.vi" Type="VI" URL="../3day/실습 8-2 글로벌 변수.vi"/>
			<Item Name="실습 8-2 글로벌 변수02.vi" Type="VI" URL="../3day/실습 8-2 글로벌 변수02.vi"/>
			<Item Name="실습 9-1 경로 만들기.vi" Type="VI" URL="../3day/실습 9-1 경로 만들기.vi"/>
		</Item>
		<Item Name="의존성" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Application Directory.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Application Directory.vi"/>
				<Item Name="Check if File or Folder Exists.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Check if File or Folder Exists.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="NI_MABase.lvlib" Type="Library" URL="/&lt;vilib&gt;/measure/NI_MABase.lvlib"/>
				<Item Name="NI_PackedLibraryUtility.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/LVLibp/NI_PackedLibraryUtility.lvlib"/>
				<Item Name="NI_PtbyPt.lvlib" Type="Library" URL="/&lt;vilib&gt;/ptbypt/NI_PtbyPt.lvlib"/>
				<Item Name="subTimeDelay.vi" Type="VI" URL="/&lt;vilib&gt;/express/express execution control/TimeDelayBlock.llb/subTimeDelay.vi"/>
				<Item Name="VISA Configure Serial Port" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port"/>
				<Item Name="VISA Configure Serial Port (Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Instr).vi"/>
				<Item Name="VISA Configure Serial Port (Serial Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Serial Instr).vi"/>
			</Item>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
		</Item>
		<Item Name="빌드 스펙" Type="Build"/>
	</Item>
</Project>
