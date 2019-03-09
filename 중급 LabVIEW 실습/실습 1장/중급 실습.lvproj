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
		<Item Name="Master_S (이벤트).vi" Type="VI" URL="../VIs/Master_S (이벤트).vi"/>
		<Item Name="Master_S.vi" Type="VI" URL="../VIs/Master_S.vi"/>
		<Item Name="Status.ctl" Type="VI" URL="../VIs/Status.ctl"/>
		<Item Name="상태머신.vi" Type="VI" URL="../VIs/상태머신.vi"/>
		<Item Name="생산자 소비자.vi" Type="VI" URL="../VIs/생산자 소비자.vi"/>
		<Item Name="생산자소비자(상태머신)-수정.vi" Type="VI" URL="../VIs/생산자소비자(상태머신)-수정.vi"/>
		<Item Name="생산자소비자(상태머신).vi" Type="VI" URL="../VIs/생산자소비자(상태머신).vi"/>
		<Item Name="실습 1-2 마스트슬레이브.vi" Type="VI" URL="../VIs/실습 1-2 마스트슬레이브.vi"/>
		<Item Name="실습 2-1.vi" Type="VI" URL="../VIs/실습 2-1.vi"/>
		<Item Name="이벤트 (열거형).vi" Type="VI" URL="../VIs/이벤트 (열거형).vi"/>
		<Item Name="이벤트 예제.vi" Type="VI" URL="../VIs/이벤트 예제.vi"/>
		<Item Name="이벤트 핸들러.vi" Type="VI" URL="../VIs/이벤트 핸들러.vi"/>
		<Item Name="의존성" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
			</Item>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
		</Item>
		<Item Name="빌드 스펙" Type="Build"/>
	</Item>
</Project>
