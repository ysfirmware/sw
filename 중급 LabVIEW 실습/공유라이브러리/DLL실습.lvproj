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
		<Item Name="ArrayFile.vi" Type="VI" URL="../../ArrayFile.vi"/>
		<Item Name="상태.ctl" Type="VI" URL="../상태.ctl"/>
		<Item Name="실습 7-1.vi" Type="VI" URL="../../실습 7-1.vi"/>
		<Item Name="실습 7-2.vi" Type="VI" URL="../../실습 7-2.vi"/>
		<Item Name="실습 7-4.vi" Type="VI" URL="../../실습 7-4.vi"/>
		<Item Name="의존성" Type="Dependencies">
			<Item Name="kernel32.dll" Type="Document" URL="kernel32.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="SharedLib.dll" Type="Document" URL="../../builds/DLL실습/나의 DLL/SharedLib.dll"/>
		</Item>
		<Item Name="빌드 스펙" Type="Build">
			<Item Name="나의 DLL" Type="DLL">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{3DF166B7-87BA-4FBD-81A3-51B59B0FB5DA}</Property>
				<Property Name="App_INI_GUID" Type="Str">{B8D0E39F-DDDC-410C-A128-9543FCAE311C}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.edu.com</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{645027E0-13CA-44BD-AEBE-86E4CF5531B6}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">나의 DLL</Property>
				<Property Name="Bld_defaultLanguage" Type="Str">Korean</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/나의 DLL</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{CB60256E-8171-4C61-B622-7564C9C6B95C}</Property>
				<Property Name="Bld_version.build" Type="Int">2</Property>
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
				<Property Name="Dll_headerGUID" Type="Str">{6F41554B-109B-41F3-A663-3D6AD02AB9C3}</Property>
				<Property Name="Dll_libGUID" Type="Str">{6009465F-C0E6-4B8C-A18C-2CD4A45B9AA3}</Property>
				<Property Name="Source[0].itemID" Type="Str">{805E99CC-0382-434E-9406-093C02EABDDC}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/내 컴퓨터/ArrayFile.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">ExportedVI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">edu</Property>
				<Property Name="TgtF_fileDescription" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_internalName" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">저작권 2015 edu</Property>
				<Property Name="TgtF_productName" Type="Str">나의 DLL</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{77A9DA65-A776-4215-B041-3B3653282C48}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">SharedLib.dll</Property>
			</Item>
		</Item>
	</Item>
</Project>
