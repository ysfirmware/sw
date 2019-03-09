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
		<Item Name="ArrayFile.vi" Type="VI" URL="../ArrayFile.vi"/>
		<Item Name="DLL 사용.vi" Type="VI" URL="../DLL 사용.vi"/>
		<Item Name="의존성" Type="Dependencies">
			<Item Name="SharedLib.dll" Type="Document" URL="../../builds/공유라이브러리 만들기/나의 DLL/SharedLib.dll"/>
		</Item>
		<Item Name="빌드 스펙" Type="Build">
			<Item Name="나의 DLL" Type="DLL">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{D1090951-06CD-4ED9-9A6D-EFDC109CDA50}</Property>
				<Property Name="App_INI_GUID" Type="Str">{731CD4E1-11C8-4EE1-B4A0-30A905F8A32B}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{643217AF-EC67-42A0-8D36-3769E9AB0FB1}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">나의 DLL</Property>
				<Property Name="Bld_defaultLanguage" Type="Str">Korean</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/나의 DLL</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{841577A0-00ED-4DF4-94F1-B4DFAD4868BF}</Property>
				<Property Name="Bld_version.build" Type="Int">1</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">SharedLib.dll</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/나의 DLL/SharedLib.dll</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">지원 디렉토리</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/나의 DLL/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Dll_compatibilityWith2011" Type="Bool">false</Property>
				<Property Name="Dll_delayOSMsg" Type="Bool">true</Property>
				<Property Name="Dll_headerGUID" Type="Str">{73CB3C79-2211-4814-A910-CFBD72F96327}</Property>
				<Property Name="Dll_libGUID" Type="Str">{760D12AB-3CFB-44FC-94CE-07E1BB61E4CE}</Property>
				<Property Name="Source[0].itemID" Type="Str">{94774500-7609-4CFE-B1D6-D2D01D73F1B7}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/내 컴퓨터/ArrayFile.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">ExportedVI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_fileDescription" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_internalName" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">저작권 2015 </Property>
				<Property Name="TgtF_productName" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{C5177651-75DB-4047-9524-BAF09A87FEAC}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">SharedLib.dll</Property>
			</Item>
		</Item>
	</Item>
</Project>
