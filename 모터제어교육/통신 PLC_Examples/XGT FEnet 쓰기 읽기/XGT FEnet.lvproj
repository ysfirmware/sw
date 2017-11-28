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
		<Item Name="Company Header 일부.vi" Type="VI" URL="../../XGB 통신 Cnet 예제/XGB/Company Header 일부.vi"/>
		<Item Name="TCP 기다림(SubVI).vi" Type="VI" URL="../TCP 기다림(SubVI).vi"/>
		<Item Name="개별쓰기(Main).vi" Type="VI" URL="../개별쓰기(Main).vi"/>
		<Item Name="개별쓰기요구(subVI).vi" Type="VI" URL="../개별쓰기요구(subVI).vi"/>
		<Item Name="개별읽기(Main).vi" Type="VI" URL="../개별읽기(Main).vi"/>
		<Item Name="개별읽기요구(subVI).vi" Type="VI" URL="../개별읽기요구(subVI).vi"/>
		<Item Name="개별읽기응답(SubVI).vi" Type="VI" URL="../개별읽기응답(SubVI).vi"/>
		<Item Name="연속쓰기(Main).vi" Type="VI" URL="../연속쓰기(Main).vi"/>
		<Item Name="연속쓰기요구(subVI).vi" Type="VI" URL="../연속쓰기요구(subVI).vi"/>
		<Item Name="연속읽기(Main).vi" Type="VI" URL="../연속읽기(Main).vi"/>
		<Item Name="연속읽기요구(subVI).vi" Type="VI" URL="../연속읽기요구(subVI).vi"/>
		<Item Name="연속읽기응답(subVI).vi" Type="VI" URL="../연속읽기응답(subVI).vi"/>
		<Item Name="의존성" Type="Dependencies"/>
		<Item Name="빌드 스펙" Type="Build"/>
	</Item>
</Project>
