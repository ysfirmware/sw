<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="14008000">
	<Property Name="varPersistentID:{7B6AA405-1000-42D8-BEBC-C8A22886ABFC}" Type="Ref">/내 컴퓨터/my변수.lvlib/Data</Property>
	<Property Name="varPersistentID:{891566A4-76B5-43C1-ACD9-7A5351E08638}" Type="Ref">/내 컴퓨터/my변수.lvlib/배열</Property>
	<Property Name="varPersistentID:{8A2C0C49-0D05-4BC1-B0D8-D12EAEA760B4}" Type="Ref">/내 컴퓨터/my변수.lvlib/Stop</Property>
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
		<Item Name="my변수.lvlib" Type="Library" URL="../my변수.lvlib"/>
		<Item Name="배열 글로벌.vi" Type="VI" URL="../배열 글로벌.vi"/>
		<Item Name="변수.vi" Type="VI" URL="../변수.vi"/>
		<Item Name="변수02.vi" Type="VI" URL="../변수02.vi"/>
		<Item Name="의존성" Type="Dependencies">
			<Item Name="my글로벌.vi" Type="VI" URL="../my글로벌.vi"/>
		</Item>
		<Item Name="빌드 스펙" Type="Build"/>
	</Item>
</Project>
