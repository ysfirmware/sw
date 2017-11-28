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
		<Item Name="DLL 호출.vi" Type="VI" URL="../DLL 호출.vi"/>
		<Item Name="의존성" Type="Dependencies">
			<Item Name="SharedLib.dll" Type="Document" URL="../../builds/공유라이브러리만들기/나의 DLL/SharedLib.dll"/>
		</Item>
		<Item Name="빌드 스펙" Type="Build">
			<Item Name="나의 DLL" Type="DLL">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{A4ADDFA6-22FA-457A-8D74-5370B500868D}</Property>
				<Property Name="App_INI_GUID" Type="Str">{F3DD91C5-0A3B-4CE1-AE93-53885A8AD8FE}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.edu.com</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{585C1C4E-363E-4961-8C38-1BCC1EE9D0AD}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">나의 DLL</Property>
				<Property Name="Bld_defaultLanguage" Type="Str">Korean</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/나의 DLL</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{33A53BD1-1429-4510-B8EC-E796AE9A8577}</Property>
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
				<Property Name="Dll_headerGUID" Type="Str">{5BE9A73D-085E-4F9B-8FC6-07C774015AD2}</Property>
				<Property Name="Dll_libGUID" Type="Str">{B5D2EA61-13B7-478E-936A-87150A4C792A}</Property>
				<Property Name="Source[0].itemID" Type="Str">{5E5C6D9A-62B7-43C8-96E7-6D85F0A59FEE}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/내 컴퓨터/ArrayFile.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">ExportedVI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">edu</Property>
				<Property Name="TgtF_fileDescription" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_internalName" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">저작권 2017 edu</Property>
				<Property Name="TgtF_productName" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{C266426F-69E8-43FA-9FEE-D91BD63B02C6}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">SharedLib.dll</Property>
			</Item>
		</Item>
	</Item>
</Project>
