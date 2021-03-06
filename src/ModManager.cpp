// Copyright © 2008-2012 Pioneer Developers. See AUTHORS.txt for details
// Licensed under the terms of the GPL v3. See licenses/GPL-3.txt

#include "ModManager.h"
#include "FileSystem.h"
#include "FileSourceZip.h"
#include "utils.h"

void ModManager::Init() {
	FileSystem::rawFileSystem.MakeDirectory(FileSystem::GetUserDir("mods"));

	FileSystem::FileSourceFS modFiles(FileSystem::GetUserDir("mods"));
	for (FileSystem::FileEnumerator files(modFiles, "", 0); !files.Finished(); files.Next()) {
		const FileSystem::FileInfo &info = files.Current();
		const std::string &zipPath = info.GetPath();
		if (ends_with(zipPath, ".zip")) {
			printf("adding mod: %s\n", zipPath.c_str());
			FileSystem::gameDataFiles.PrependSource(new FileSystem::FileSourceZip(FileSystem::JoinPathBelow(modFiles.GetRoot(), zipPath)));
		}
	}
}
