#include "shlobj_core.h"

#include <cstring>
#include <iostream>
#include <winerror.h>
#include <sys/stat.h>

namespace {
  KNOWNFOLDERID FOLDERID_AccountPictures = { 0x008CA0B1, 0x55B4, 0x4C56, { 0xB8, 0xA8, 0x4D, 0xE4, 0xB2, 0x99, 0xD3, 0xBE } };
  KNOWNFOLDERID FOLDERID_AddNewPrograms = { 0xDE61D971, 0x5EBC, 0x4F02, { 0xA3, 0xA9, 0x6C, 0x82, 0x89, 0x5E, 0x5C, 0x04 } };
  KNOWNFOLDERID FOLDERID_AdminTools = { 0x724EF170, 0xA42D, 0x4FEF, { 0x9F, 0x26, 0xB6, 0x0E, 0x84, 0x6F, 0xBA, 0x4F } };
  KNOWNFOLDERID FOLDERID_AppDataDesktop = { 0xB2C5E279, 0x7ADD, 0x439F, { 0xB2, 0x8C, 0xC4, 0x1F, 0xE1, 0xBB, 0xF6, 0x72 } };
  KNOWNFOLDERID FOLDERID_AppDataDocuments = { 0x7BE16610, 0x1F7F, 0x44AC, { 0xBF, 0xF0, 0x83, 0xE1, 0x5F, 0x2F, 0xFC, 0xA1 } };
  KNOWNFOLDERID FOLDERID_AppDataFavorites = { 0x7CFBEFBC, 0xDE1F, 0x45AA, { 0xB8, 0x43, 0xA5, 0x42, 0xAC, 0x53, 0x6C, 0xC9 } };
  KNOWNFOLDERID FOLDERID_AppDataProgramData = { 0x559D40A3, 0xA036, 0x40FA, { 0xAF, 0x61, 0x84, 0xCB, 0x43, 0x0A, 0x4D, 0x34 } };
  KNOWNFOLDERID FOLDERID_ApplicationShortcuts = { 0xA3918781, 0xE5F2, 0x4890, { 0xB3, 0xD9, 0xA7, 0xE5, 0x43, 0x32, 0x32, 0x8C } };
  KNOWNFOLDERID FOLDERID_AppsFolder = { 0x1E87508D, 0x89C2, 0x42F0, { 0x8A, 0x7E, 0x64, 0x5A, 0x0F, 0x50, 0xCA, 0x58 } };
  KNOWNFOLDERID FOLDERID_AppUpdates = { 0xA305CE99, 0xF527, 0x492B, { 0x8B, 0x1A, 0x7E, 0x76, 0xFA, 0x98, 0xD6, 0xE4 } };
  KNOWNFOLDERID FOLDERID_CameraRoll = { 0xAB5FB87B, 0x7CE2, 0x4F83, { 0x91, 0x5D, 0x55, 0x08, 0x46, 0xC9, 0x53, 0x7B } };
  KNOWNFOLDERID FOLDERID_CDBurning = { 0x9E52AB10, 0xF80D, 0x49DF, { 0xAC, 0xB8, 0x43, 0x30, 0xF5, 0x68, 0x78, 0x55 } };
  KNOWNFOLDERID FOLDERID_ChangeRemovePrograms = { 0xDF7266AC, 0x9274, 0x4867, { 0x8D, 0x55, 0x3B, 0xD6, 0x61, 0xDE, 0x87, 0x2D } };
  KNOWNFOLDERID FOLDERID_CommonAdminTools = { 0xD0384E7D, 0xBAC3, 0x4797, { 0x8F, 0x14, 0xCB, 0xA2, 0x29, 0xB3, 0x92, 0xB5 } };
  KNOWNFOLDERID FOLDERID_CommonOEMLinks = { 0xC1BAE2D0, 0x10DF, 0x4334, { 0xBE, 0xDD, 0x7A, 0xA2, 0x0B, 0x22, 0x7A, 0x9D } };
  KNOWNFOLDERID FOLDERID_CommonPrograms = { 0x0139D44E, 0x6AFE, 0x49F2, { 0x86, 0x90, 0x3D, 0xAF, 0xCA, 0xE6, 0xFF, 0xB8 } };
  KNOWNFOLDERID FOLDERID_CommonStartMenu = { 0xA4115719, 0xD62E, 0x491D, { 0xAA, 0x7C, 0xE7, 0x4B, 0x8B, 0xE3, 0xB0, 0x67 } };
  KNOWNFOLDERID FOLDERID_CommonStartup = { 0x82A5EA35, 0xD9CD, 0x47C5, { 0x96, 0x29, 0xE1, 0x5D, 0x2F, 0x71, 0x4E, 0x6E } };
  KNOWNFOLDERID FOLDERID_CommonTemplates = { 0xB94237E7, 0x57AC, 0x4347, { 0x91, 0x51, 0xB0, 0x8C, 0x6C, 0x32, 0xD1, 0xF7 } };
  KNOWNFOLDERID FOLDERID_ComputerFolder = { 0x0AC0837C, 0xBBF8, 0x452A, { 0x85, 0x0D, 0x79, 0xD0, 0x8E, 0x66, 0x7C, 0xA7 } };
  KNOWNFOLDERID FOLDERID_ConflictFolder = { 0x4BFEFB45, 0x347D, 0x4006, { 0xA5, 0xBE, 0xAC, 0x0C, 0xB0, 0x56, 0x71, 0x92 } };
  KNOWNFOLDERID FOLDERID_ConnectionsFolder = { 0x6F0CD92B, 0x2E97, 0x45D1, { 0x88, 0xFF, 0xB0, 0xD1, 0x86, 0xB8, 0xDE, 0xDD } };
  KNOWNFOLDERID FOLDERID_Contacts = { 0x56784854, 0xC6CB, 0x462B, { 0x81, 0x69, 0x88, 0xE3, 0x50, 0xAC, 0xB8, 0x82 } };
  KNOWNFOLDERID FOLDERID_ControlPanelFolder = { 0x82A74AEB, 0xAEB4, 0x465C, { 0xA0, 0x14, 0xD0, 0x97, 0xEE, 0x34, 0x6D, 0x63 } };
  KNOWNFOLDERID FOLDERID_Cookies = { 0x2B0F765D, 0xC0E9, 0x4171, { 0x90, 0x8E, 0x08, 0xA6, 0x11, 0xB8, 0x4F, 0xF6 } };
  KNOWNFOLDERID FOLDERID_Desktop = { 0xB4BFCC3A, 0xDB2C, 0x424C, { 0xB0, 0x29, 0x7F, 0xE9, 0x9A, 0x87, 0xC6, 0x41 } };
  KNOWNFOLDERID FOLDERID_DeviceMetadataStore = { 0x5CE4A5E9, 0xE4EB, 0x479D, { 0xB8, 0x9F, 0x13, 0x0C, 0x02, 0x88, 0x61, 0x55 } };
  KNOWNFOLDERID FOLDERID_Documents = { 0xFDD39AD0, 0x238F, 0x46AF, { 0xAD, 0xB4, 0x6C, 0x85, 0x48, 0x03, 0x69, 0xC7 } };
  KNOWNFOLDERID FOLDERID_DocumentsLibrary = { 0x7B0DB17D, 0x9CD2, 0x4A93, { 0x97, 0x33, 0x46, 0xCC, 0x89, 0x02, 0x2E, 0x7C } };
  KNOWNFOLDERID FOLDERID_Downloads = { 0x374DE290, 0x123F, 0x4565, { 0x91, 0x64, 0x39, 0xC4, 0x92, 0x5E, 0x46, 0x7B } };
  KNOWNFOLDERID FOLDERID_Favorites = { 0x1777F761, 0x68AD, 0x4D8A, { 0x87, 0xBD, 0x30, 0xB7, 0x59, 0xFA, 0x33, 0xDD } };
  KNOWNFOLDERID FOLDERID_Fonts = { 0xFD228CB7, 0xAE11, 0x4AE3, { 0x86, 0x4C, 0x16, 0xF3, 0x91, 0x0A, 0xB8, 0xFE } };
  KNOWNFOLDERID FOLDERID_Games = { 0xCAC52C1A, 0xB53D, 0x4EDC, { 0x92, 0xD7, 0x6B, 0x2E, 0x8A, 0xC1, 0x94, 0x34 } };
  KNOWNFOLDERID FOLDERID_GameTasks = { 0x054FAE61, 0x4DD8, 0x4787, { 0x80, 0xB6, 0x09, 0x02, 0x20, 0xC4, 0xB7, 0x00 } };
  KNOWNFOLDERID FOLDERID_History = { 0xD9DC8A3B, 0xB784, 0x432E, { 0xA7, 0x81, 0x5A, 0x11, 0x30, 0xA7, 0x59, 0x63 } };
  KNOWNFOLDERID FOLDERID_HomeGroup = { 0x52528A6B, 0xB9E3, 0x4ADD, { 0xB6, 0x0D, 0x58, 0x8C, 0x2D, 0xBA, 0x84, 0x2D } };
  KNOWNFOLDERID FOLDERID_HomeGroupCurrentUser = { 0x9B74B6A3, 0x0DFD, 0x4F11, { 0x9E, 0x78, 0x5F, 0x78, 0x00, 0xF2, 0xE7, 0x72 } };
  KNOWNFOLDERID FOLDERID_ImplicitAppShortcuts = { 0xBCB5256F, 0x79F6, 0x4CEE, { 0xB7, 0x25, 0xDC, 0x34, 0xE4, 0x02, 0xFD, 0x46 } };
  KNOWNFOLDERID FOLDERID_InternetCache = { 0x352481E8, 0x33BE, 0x4251, { 0xBA, 0x85, 0x60, 0x07, 0xCA, 0xED, 0xCF, 0x9D } };
  KNOWNFOLDERID FOLDERID_InternetFolder = { 0x4D9F7874, 0x4E0C, 0x4904, { 0x96, 0x7B, 0x40, 0xB0, 0xD2, 0x0C, 0x3E, 0x4B } };
  KNOWNFOLDERID FOLDERID_Libraries = { 0x1B3EA5DC, 0xB587, 0x4786, { 0xB4, 0xEF, 0xBD, 0x1D, 0xC3, 0x32, 0xAE, 0xAE } };
  KNOWNFOLDERID FOLDERID_Links = { 0xBFB9D5E0, 0xC6A9, 0x404C, { 0xB2, 0xB2, 0xAE, 0x6D, 0xB6, 0xAF, 0x49, 0x68 } };
  KNOWNFOLDERID FOLDERID_LocalAppData = { 0xF1B32785, 0x6FBA, 0x4FCF, { 0x9D, 0x55, 0x7B, 0x8E, 0x7F, 0x15, 0x70, 0x91 } };
  KNOWNFOLDERID FOLDERID_LocalAppDataLow = { 0xA520A1A4, 0x1780, 0x4FF6, { 0xBD, 0x18, 0x16, 0x73, 0x43, 0xC5, 0xAF, 0x16 } };
  KNOWNFOLDERID FOLDERID_LocalizedResourcesDir = { 0x2A00375E, 0x224C, 0x49DE, { 0xB8, 0xD1, 0x44, 0x0D, 0xF7, 0xEF, 0x3D, 0xDC } };
  KNOWNFOLDERID FOLDERID_Music = { 0x4BD8D571, 0x6D19, 0x48D3, { 0xBE, 0x97, 0x42, 0x22, 0x20, 0x08, 0x0E, 0x43 } };
  KNOWNFOLDERID FOLDERID_MusicLibrary = { 0x2112AB0A, 0xC86A, 0x4FFE, { 0xA3, 0x68, 0x0D, 0xE9, 0x6E, 0x47, 0x01, 0x2E } };
  KNOWNFOLDERID FOLDERID_NetHood = { 0xC5ABBF53, 0xE17F, 0x4121, { 0x89, 0x00, 0x86, 0x62, 0x6F, 0xC2, 0xC9, 0x73 } };
  KNOWNFOLDERID FOLDERID_NetworkFolder = { 0xD20BEEC4, 0x5CA8, 0x4905, { 0xAE, 0x3B, 0xBF, 0x25, 0x1E, 0xA0, 0x9B, 0x52 } };
  KNOWNFOLDERID FOLDERID_Objects3D = { 0x31C0DD25, 0x9439, 0x4F12, { 0xBF, 0x41, 0x7F, 0xF4, 0xED, 0xA3, 0x87, 0x22 } };
  KNOWNFOLDERID FOLDERID_OriginalImages = { 0x2C36C0AA, 0x5812, 0x4B87, { 0xBF, 0xD0, 0x4C, 0xD0, 0xDF, 0xB1, 0x9B, 0x39 } };
  KNOWNFOLDERID FOLDERID_PhotoAlbums = { 0x69D2CF90, 0xFC33, 0x4FB7, { 0x9A, 0x0C, 0xEB, 0xB0, 0xF0, 0xFC, 0xB4, 0x3C } };
  KNOWNFOLDERID FOLDERID_PicturesLibrary = { 0xA990AE9F, 0xA03B, 0x4E80, { 0x94, 0xBC, 0x99, 0x12, 0xD7, 0x50, 0x41, 0x04 } };
  KNOWNFOLDERID FOLDERID_Pictures = { 0x33E28130, 0x4E1E, 0x4676, { 0x83, 0x5A, 0x98, 0x39, 0x5C, 0x3B, 0xC3, 0xBB } };
  KNOWNFOLDERID FOLDERID_Playlists = { 0xDE92C1C7, 0x837F, 0x4F69, { 0xA3, 0xBB, 0x86, 0xE6, 0x31, 0x20, 0x4A, 0x23 } };
  KNOWNFOLDERID FOLDERID_PrintersFolder = { 0x76FC4E2D, 0xD6AD, 0x4519, { 0xA6, 0x63, 0x37, 0xBD, 0x56, 0x06, 0x81, 0x85 } };
  KNOWNFOLDERID FOLDERID_PrintHood = { 0x9274BD8D, 0xCFD1, 0x41C3, { 0xB3, 0x5E, 0xB1, 0x3F, 0x55, 0xA7, 0x58, 0xF4 } };
  KNOWNFOLDERID FOLDERID_Profile = { 0x5E6C858F, 0x0E22, 0x4760, { 0x9A, 0xFE, 0xEA, 0x33, 0x17, 0xB6, 0x71, 0x73 } };
  KNOWNFOLDERID FOLDERID_ProgramData = { 0x62AB5D82, 0xFDC1, 0x4DC3, { 0xA9, 0xDD, 0x07, 0x0D, 0x1D, 0x49, 0x5D, 0x97 } };
  KNOWNFOLDERID FOLDERID_ProgramFiles = { 0x905E63B6, 0xC1BF, 0x494E, { 0xB2, 0x9C, 0x65, 0xB7, 0x32, 0xD3, 0xD2, 0x1A } };
  KNOWNFOLDERID FOLDERID_ProgramFilesX64 = { 0x6D809377, 0x6AF0, 0x444B, { 0x89, 0x57, 0xA3, 0x77, 0x3F, 0x02, 0x20, 0x0E } };
  KNOWNFOLDERID FOLDERID_ProgramFilesX86 = { 0x7C5A40EF, 0xA0FB, 0x4BFC, { 0x87, 0x4A, 0xC0, 0xF2, 0xE0, 0xB9, 0xFA, 0x83 } };
  KNOWNFOLDERID FOLDERID_ProgramFilesCommon = { 0xF7F1ED05, 0x9F6D, 0x47A2, { 0xAA, 0xAE, 0x29, 0xD3, 0x17, 0xC6, 0xF0, 0x66 } };
  KNOWNFOLDERID FOLDERID_ProgramFilesCommonX64 = { 0x6365D5A7, 0x0F0D, 0x45E5, { 0x87, 0xF6, 0x0D, 0xA5, 0x6B, 0x6A, 0x4F, 0x7D } };
  KNOWNFOLDERID FOLDERID_ProgramFilesCommonX86 = { 0xDE974D24, 0xD9C6, 0x4D3E, { 0xBF, 0x91, 0xF4, 0x45, 0x51, 0x20, 0xB9, 0x17 } };
  KNOWNFOLDERID FOLDERID_Programs = { 0xA77F5D77, 0x2E2B, 0x44C3, { 0xA6, 0xA2, 0xAB, 0xA6, 0x01, 0x05, 0x4A, 0x51 } };
  KNOWNFOLDERID FOLDERID_Public = { 0xDFDF76A2, 0xC82A, 0x4D63, { 0x90, 0x6A, 0x56, 0x44, 0xAC, 0x45, 0x73, 0x85 } };
  KNOWNFOLDERID FOLDERID_PublicDesktop = { 0xC4AA340D, 0xF20F, 0x4863, { 0xAF, 0xEF, 0xF8, 0x7E, 0xF2, 0xE6, 0xBA, 0x25 } };
  KNOWNFOLDERID FOLDERID_PublicDocuments = { 0xED4824AF, 0xDCE4, 0x45A8, { 0x81, 0xE2, 0xFC, 0x79, 0x65, 0x08, 0x36, 0x34 } };
  KNOWNFOLDERID FOLDERID_PublicDownloads = { 0x3D644C9B, 0x1FB8, 0x4F30, { 0x9B, 0x45, 0xF6, 0x70, 0x23, 0x5F, 0x79, 0xC0 } };
  KNOWNFOLDERID FOLDERID_PublicGameTasks = { 0xDEBF2536, 0xE1A8, 0x4C59, { 0xB6, 0xA2, 0x41, 0x45, 0x86, 0x47, 0x6A, 0xEA } };
  KNOWNFOLDERID FOLDERID_PublicLibraries = { 0x48DAF80B, 0xE6CF, 0x4F4E, { 0xB8, 0x00, 0x0E, 0x69, 0xD8, 0x4E, 0xE3, 0x84 } };
  KNOWNFOLDERID FOLDERID_PublicMusic = { 0x3214FAB5, 0x9757, 0x4298, { 0xBB, 0x61, 0x92, 0xA9, 0xDE, 0xAA, 0x44, 0xFF } };
  KNOWNFOLDERID FOLDERID_PublicPictures = { 0xB6EBFB86, 0x6907, 0x413C, { 0x9A, 0xF7, 0x4F, 0xC2, 0xAB, 0xF0, 0x7C, 0xC5 } };
  KNOWNFOLDERID FOLDERID_PublicRingtones = { 0xE555AB60, 0x153B, 0x4D17, { 0x9F, 0x04, 0xA5, 0xFE, 0x99, 0xFC, 0x15, 0xEC } };
  KNOWNFOLDERID FOLDERID_PublicUserTiles = { 0x0482AF6C, 0x08F1, 0x4C34, { 0x8C, 0x90, 0xE1, 0x7E, 0xC9, 0x8B, 0x1E, 0x17 } };
  KNOWNFOLDERID FOLDERID_PublicVideos = { 0x2400183A, 0x6185, 0x49FB, { 0xA2, 0xD8, 0x4A, 0x39, 0x2A, 0x60, 0x2B, 0xA3 } };
  KNOWNFOLDERID FOLDERID_QuickLaunch = { 0x52A4F021, 0x7B75, 0x48A9, { 0x9F, 0x6B, 0x4B, 0x87, 0xA2, 0x10, 0xBC, 0x8F } };
  KNOWNFOLDERID FOLDERID_Recent = { 0xAE50C081, 0xEBD2, 0x438A, { 0x86, 0x55, 0x8A, 0x09, 0x2E, 0x34, 0x98, 0x7A } };
  KNOWNFOLDERID FOLDERID_RecordedTVLibrary = { 0x1A6FDBA2, 0xF42D, 0x4358, { 0xA7, 0x98, 0xB7, 0x4D, 0x74, 0x59, 0x26, 0xC5 } };
  KNOWNFOLDERID FOLDERID_RecycleBinFolder = { 0xB7534046, 0x3ECB, 0x4C18, { 0xBE, 0x4E, 0x64, 0xCD, 0x4C, 0xB7, 0xD6, 0xAC } };
  KNOWNFOLDERID FOLDERID_ResourceDir = { 0x8AD10C31, 0x2ADB, 0x4296, { 0xA8, 0xF7, 0xE4, 0x70, 0x12, 0x32, 0xC9, 0x72 } };
  KNOWNFOLDERID FOLDERID_Ringtones = { 0xC870044B, 0xF49E, 0x4126, { 0xA9, 0xC3, 0xB5, 0x2A, 0x1F, 0xF4, 0x11, 0xE8 } };
  KNOWNFOLDERID FOLDERID_RoamingAppData = { 0x3EB685DB, 0x65F9, 0x4CF6, { 0xA0, 0x3A, 0xE3, 0xEF, 0x65, 0x72, 0x9F, 0x3D } };
  KNOWNFOLDERID FOLDERID_RoamedTileImages = { 0xAAA8D5A5, 0xF1D6, 0x4259, { 0xBA, 0xA8, 0x78, 0xE7, 0xEF, 0x60, 0x83, 0x5E } };
  KNOWNFOLDERID FOLDERID_RoamingTiles = { 0x00BCFC5A, 0xED94, 0x4E48, { 0x96, 0xA1, 0x3F, 0x62, 0x17, 0xF2, 0x19, 0x90 } };
  KNOWNFOLDERID FOLDERID_SampleMusic = { 0xB250C668, 0xF57D, 0x4EE1, { 0xA6, 0x3C, 0x29, 0x0E, 0xE7, 0xD1, 0xAA, 0x1F } };
  KNOWNFOLDERID FOLDERID_SamplePictures = { 0xC4900540, 0x2379, 0x4C75, { 0x84, 0x4B, 0x64, 0xE6, 0xFA, 0xF8, 0x71, 0x6B } };
  KNOWNFOLDERID FOLDERID_SamplePlaylists = { 0x15CA69B3, 0x30EE, 0x49C1, { 0xAC, 0xE1, 0x6B, 0x5E, 0xC3, 0x72, 0xAF, 0xB5 } };
  KNOWNFOLDERID FOLDERID_SampleVideos = { 0x859EAD94, 0x2E85, 0x48AD, { 0xA7, 0x1A, 0x09, 0x69, 0xCB, 0x56, 0xA6, 0xCD } };
  KNOWNFOLDERID FOLDERID_SavedGames = { 0x4C5C32FF, 0xBB9D, 0x43B0, { 0xB5, 0xB4, 0x2D, 0x72, 0xE5, 0x4E, 0xAA, 0xA4 } };
  KNOWNFOLDERID FOLDERID_SavedPictures = { 0x3B193882, 0xD3AD, 0x4EAB, { 0x96, 0x5A, 0x69, 0x82, 0x9D, 0x1F, 0xB5, 0x9F } };
  KNOWNFOLDERID FOLDERID_SavedPicturesLibrary = { 0xE25B5812, 0xBE88, 0x4BD9, { 0x94, 0xB0, 0x29, 0x23, 0x34, 0x77, 0xB6, 0xC3 } };
  KNOWNFOLDERID FOLDERID_SavedSearches = { 0x7D1D3A04, 0xDEBB, 0x4115, { 0x95, 0xCF, 0x2F, 0x29, 0xDA, 0x29, 0x20, 0xDA } };
  KNOWNFOLDERID FOLDERID_Screenshots = { 0xB7BEDE81, 0xDF94, 0x4682, { 0xA7, 0xD8, 0x57, 0xA5, 0x26, 0x20, 0xB8, 0x6F } };
  KNOWNFOLDERID FOLDERID_SEARCH_CSC = { 0xEE32E446, 0x31CA, 0x4ABA, { 0x81, 0x4F, 0xA5, 0xEB, 0xD2, 0xFD, 0x6D, 0x5E } };
  KNOWNFOLDERID FOLDERID_SearchHistory = { 0x0D4C3DB6, 0x03A3, 0x462F, { 0xA0, 0xE6, 0x08, 0x92, 0x4C, 0x41, 0xB5, 0xD4 } };
  KNOWNFOLDERID FOLDERID_SearchHome = { 0x190337D1, 0xB8CA, 0x4121, { 0xA6, 0x39, 0x6D, 0x47, 0x2D, 0x16, 0x97, 0x2A } };
  KNOWNFOLDERID FOLDERID_SEARCH_MAPI = { 0x98EC0E18, 0x2098, 0x4D44, { 0x86, 0x44, 0x66, 0x97, 0x93, 0x15, 0xA2, 0x81 } };
  KNOWNFOLDERID FOLDERID_SearchTemplates = { 0x7E636BFE, 0xDFA9, 0x4D5E, { 0xB4, 0x56, 0xD7, 0xB3, 0x98, 0x51, 0xD8, 0xA9 } };
  KNOWNFOLDERID FOLDERID_SendTo = { 0x8983036C, 0x27C0, 0x404B, { 0x8F, 0x08, 0x10, 0x2D, 0x10, 0xDC, 0xFD, 0x74 } };
  KNOWNFOLDERID FOLDERID_SidebarDefaultParts = { 0x7B396E54, 0x9EC5, 0x4300, { 0xBE, 0x0A, 0x24, 0x82, 0xEB, 0xAE, 0x1A, 0x26 } };
  KNOWNFOLDERID FOLDERID_SidebarParts = { 0xA75D362E, 0x50FC, 0x4FB7, { 0xAC, 0x2C, 0xA8, 0xBE, 0xAA, 0x31, 0x44, 0x93 } };
  KNOWNFOLDERID FOLDERID_SkyDrive = { 0xA52BBA46, 0xE9E1, 0x435F, { 0xB3, 0xD9, 0x28, 0xDA, 0xA6, 0x48, 0xC0, 0xF6 } };
  KNOWNFOLDERID FOLDERID_SkyDriveCameraRoll = { 0x767E6811, 0x49CB, 0x4273, { 0x87, 0xC2, 0x20, 0xF3, 0x55, 0xE1, 0x08, 0x5B } };
  KNOWNFOLDERID FOLDERID_SkyDriveDocuments = { 0x24D89E24, 0x2F19, 0x4534, { 0x9D, 0xDE, 0x6A, 0x66, 0x71, 0xFB, 0xB8, 0xFE } };
  KNOWNFOLDERID FOLDERID_SkyDrivePictures = { 0x339719B5, 0x8C47, 0x4894, { 0x94, 0xC2, 0xD8, 0xF7, 0x7A, 0xDD, 0x44, 0xA6 } };
  KNOWNFOLDERID FOLDERID_StartMenu = { 0x625B53C3, 0xAB48, 0x4EC1, { 0xBA, 0x1F, 0xA1, 0xEF, 0x41, 0x46, 0xFC, 0x19 } };
  KNOWNFOLDERID FOLDERID_Startup = { 0xB97D20BB, 0xF46A, 0x4C97, { 0xBA, 0x10, 0x5E, 0x36, 0x08, 0x43, 0x08, 0x54 } };
  KNOWNFOLDERID FOLDERID_SyncManagerFolder = { 0x43668BF8, 0xC14E, 0x49B2, { 0x97, 0xC9, 0x74, 0x77, 0x84, 0xD7, 0x84, 0xB7 } };
  KNOWNFOLDERID FOLDERID_SyncResultsFolder = { 0x289A9A43, 0xBE44, 0x4057, { 0xA4, 0x1B, 0x58, 0x7A, 0x76, 0xD7, 0xE7, 0xF9 } };
  KNOWNFOLDERID FOLDERID_SyncSetupFolder = { 0x0F214138, 0xB1D3, 0x4A90, { 0xBB, 0xA9, 0x27, 0xCB, 0xC0, 0xC5, 0x38, 0x9A } };
  KNOWNFOLDERID FOLDERID_System = { 0x1AC14E77, 0x02E7, 0x4E5D, { 0xB7, 0x44, 0x2E, 0xB1, 0xAE, 0x51, 0x98, 0xB7 } };
  KNOWNFOLDERID FOLDERID_SystemX86 = { 0xD65231B0, 0xB2F1, 0x4857, { 0xA4, 0xCE, 0xA8, 0xE7, 0xC6, 0xEA, 0x7D, 0x27 } };
  KNOWNFOLDERID FOLDERID_Templates = { 0xA63293E8, 0x664E, 0x48DB, { 0xA0, 0x79, 0xDF, 0x75, 0x9E, 0x05, 0x09, 0xF7 } };
  KNOWNFOLDERID FOLDERID_UserPinned = { 0x9E3995AB, 0x1F9C, 0x4F13, { 0xB8, 0x27, 0x48, 0xB2, 0x4B, 0x6C, 0x71, 0x74 } };
  KNOWNFOLDERID FOLDERID_UserProfiles = { 0x0762D272, 0xC50A, 0x4BB0, { 0xA3, 0x82, 0x69, 0x7D, 0xCD, 0x72, 0x9B, 0x80 } };
  KNOWNFOLDERID FOLDERID_UserProgramFiles = { 0x5CD7AEE2, 0x2219, 0x4A67, { 0xB8, 0x5D, 0x6C, 0x9C, 0xE1, 0x56, 0x60, 0xCB } };
  KNOWNFOLDERID FOLDERID_UserProgramFilesCommon = { 0xBCBD3057, 0xCA5C, 0x4622, { 0xB4, 0x2D, 0xBC, 0x56, 0xDB, 0x0A, 0xE5, 0x16 } };
  KNOWNFOLDERID FOLDERID_UsersFiles = { 0xF3CE0F7C, 0x4901, 0x4ACC, { 0x86, 0x48, 0xD5, 0xD4, 0x4B, 0x04, 0xEF, 0x8F } };
  KNOWNFOLDERID FOLDERID_UsersLibraries = { 0xA302545D, 0xDEFF, 0x464B, { 0xAB, 0xE8, 0x61, 0xC8, 0x64, 0x8D, 0x93, 0x9B } };
  KNOWNFOLDERID FOLDERID_Videos = { 0x18989B1D, 0x99B5, 0x455B, { 0x84, 0x1C, 0xAB, 0x7C, 0x74, 0xE4, 0xDD, 0xFC } };
  KNOWNFOLDERID FOLDERID_VideosLibrary = { 0x491E922F, 0x5643, 0x4AF4, { 0xA7, 0xEB, 0x4E, 0x7A, 0x13, 0x8D, 0x81, 0x74 } };
  KNOWNFOLDERID FOLDERID_Windows = { 0xF38BF404, 0x1D43, 0x42F2, { 0x93, 0x05, 0x67, 0xDE, 0x0B, 0x28, 0xFC, 0x23 } };
};

HRESULT WINAPI SHGetKnownFolderPath(REFKNOWNFOLDERID rfid, DWORD dwFlags, HANDLE hToken, PWSTR* ppszPath) {
  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_FORCE_APP_DATA_REDIRECTION) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_FORCE_APP_DATA_REDIRECTION" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_RETURN_FILTER_REDIRECTION_TARGET) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_RETURN_FILTER_REDIRECTION_TARGET" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_FORCE_PACKAGE_REDIRECTION) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_FORCE_PACKAGE_REDIRECTION" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_NO_PACKAGE_REDIRECTION) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_NO_PACKAGE_REDIRECTION" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_FORCE_APPCONTAINER_REDIRECTION) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_FORCE_APPCONTAINER_REDIRECTION" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_NO_APPCONTAINER_REDIRECTION) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_NO_APPCONTAINER_REDIRECTION" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_DONT_VERIFY) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_DONT_VERIFY" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_DONT_UNEXPAND) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_DONT_UNEXPAND" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_NO_ALIAS) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_NO_ALIAS" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_INIT) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_INIT" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_DEFAULT_PATH) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_DEFAULT_PATH" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_NOT_PARENT_RELATIVE) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_NOT_PARENT_RELATIVE" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_SIMPLE_IDLIST) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_SIMPLE_IDLIST" << std::endl;
  }

  if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_ALIAS_ONLY) {
    std::cout << "SHGetKnownFolderPath: Unimplemented flag: KNOWN_FOLDER_FLAG::KF_FLAG_ALIAS_ONLY" << std::endl;
  }

  if (hToken != nullptr) {
    std::cout << "SHGetKnownFolderPath: User tokens are not implemented" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_LocalAppData, sizeof(KNOWNFOLDERID)) == 0) {
    //The path for FOLDERID_LocalAppData will be $HOME/.local/share
    const char* home = getenv("HOME");
    if (!home) {
      return E_FAIL;
    }

    const char* localShare = "/.local/share";

    size_t homeLength = strlen(home);
    size_t localShareLength = strlen(localShare);

    size_t totalLength = homeLength + localShareLength;
    char* path = new char[totalLength + 1];

    memcpy(path, home, homeLength);
    memcpy(path + homeLength, localShare, localShareLength);
    path[totalLength] = 0;

    struct stat dir_info = {};
    if (stat(path, &dir_info) != 0) {
      //In case the directory doesn't exist and the KF_FLAG_CREATE flag is set, attempt to create the directory
      if (dwFlags & KNOWN_FOLDER_FLAG::KF_FLAG_CREATE) {
        if (mkdir(path, 0777) != 0) {
          delete[] path;
          return E_FAIL;
        }
      } else {
        delete[] path;
        return E_FAIL;
      }
    } else if (!(dir_info.st_mode & S_IFDIR)) {
      //In a weird case that the requested path leads to a file for some reason, there's nothing we can do
      delete[] path;
      return E_FAIL;
    }

    //If everything works properly, return the path as a WCHAR string
    char16_t* pathW = new char16_t[totalLength + 1];
    *ppszPath = pathW;

    for (int i = 0; i < totalLength + 1; i++) {
      pathW[i] = (char16_t)(path[i] & 0xFF);
    }

    delete[] path;
    return S_OK;
  }

  if (memcmp(rfid, &FOLDERID_AccountPictures, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_AccountPictures" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_AddNewPrograms, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_AddNewPrograms" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_AdminTools, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_AdminTools" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_AppDataDesktop, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_AppDataDesktop" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_AppDataDocuments, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_AppDataDocuments" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_AppDataFavorites, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_AppDataFavorites" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_AppDataProgramData, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_AppDataProgramData" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ApplicationShortcuts, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ApplicationShortcuts" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_AppsFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_AppsFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_AppUpdates, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_AppUpdates" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_CameraRoll, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_CameraRoll" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_CDBurning, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_CDBurning" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ChangeRemovePrograms, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ChangeRemovePrograms" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_CommonAdminTools, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_CommonAdminTools" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_CommonOEMLinks, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_CommonOEMLinks" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_CommonPrograms, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_CommonPrograms" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_CommonStartMenu, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_CommonStartMenu" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_CommonStartup, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_CommonStartup" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_CommonTemplates, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_CommonTemplates" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ComputerFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ComputerFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ConflictFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ConflictFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ConnectionsFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ConnectionsFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Contacts, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Contacts" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ControlPanelFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ControlPanelFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Cookies, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Cookies" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Desktop, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Desktop" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_DeviceMetadataStore, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_DeviceMetadataStore" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Documents, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Documents" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_DocumentsLibrary, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_DocumentsLibrary" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Downloads, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Downloads" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Favorites, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Favorites" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Fonts, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Fonts" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Games, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Games" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_GameTasks, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_GameTasks" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_History, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_History" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_HomeGroup, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_HomeGroup" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_HomeGroupCurrentUser, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_HomeGroupCurrentUser" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ImplicitAppShortcuts, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ImplicitAppShortcuts" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_InternetCache, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_InternetCache" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_InternetFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_InternetFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Libraries, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Libraries" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Links, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Links" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_LocalAppDataLow, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_LocalAppDataLow" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_LocalizedResourcesDir, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_LocalizedResourcesDir" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Music, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Music" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_MusicLibrary, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_MusicLibrary" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_NetHood, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_NetHood" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_NetworkFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_NetworkFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Objects3D, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Objects3D" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_OriginalImages, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_OriginalImages" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PhotoAlbums, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PhotoAlbums" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PicturesLibrary, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PicturesLibrary" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Pictures, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Pictures" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Playlists, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Playlists" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PrintersFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PrintersFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PrintHood, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PrintHood" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Profile, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Profile" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ProgramData, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ProgramData" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ProgramFiles, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ProgramFiles" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ProgramFilesX64, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ProgramFilesX64" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ProgramFilesX86, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ProgramFilesX86" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ProgramFilesCommon, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ProgramFilesCommon" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ProgramFilesCommonX64, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ProgramFilesCommonX64" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ProgramFilesCommonX86, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ProgramFilesCommonX86" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Programs, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Programs" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Public, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Public" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PublicDesktop, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PublicDesktop" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PublicDocuments, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PublicDocuments" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PublicDownloads, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PublicDownloads" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PublicGameTasks, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PublicGameTasks" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PublicLibraries, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PublicLibraries" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PublicMusic, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PublicMusic" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PublicPictures, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PublicPictures" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PublicRingtones, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PublicRingtones" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PublicUserTiles, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PublicUserTiles" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_PublicVideos, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_PublicVideos" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_QuickLaunch, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_QuickLaunch" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Recent, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Recent" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_RecordedTVLibrary, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_RecordedTVLibrary" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_RecycleBinFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_RecycleBinFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_ResourceDir, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_ResourceDir" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Ringtones, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Ringtones" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_RoamingAppData, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_RoamingAppData" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_RoamedTileImages, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_RoamedTileImages" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_RoamingTiles, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_RoamingTiles" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SampleMusic, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SampleMusic" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SamplePictures, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SamplePictures" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SamplePlaylists, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SamplePlaylists" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SampleVideos, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SampleVideos" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SavedGames, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SavedGames" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SavedPictures, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SavedPictures" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SavedPicturesLibrary, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SavedPicturesLibrary" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SavedSearches, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SavedSearches" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Screenshots, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Screenshots" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SEARCH_CSC, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SEARCH_CSC" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SearchHistory, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SearchHistory" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SearchHome, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SearchHome" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SEARCH_MAPI, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SEARCH_MAPI" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SearchTemplates, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SearchTemplates" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SendTo, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SendTo" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SidebarDefaultParts, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SidebarDefaultParts" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SidebarParts, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SidebarParts" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SkyDrive, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SkyDrive" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SkyDriveCameraRoll, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SkyDriveCameraRoll" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SkyDriveDocuments, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SkyDriveDocuments" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SkyDrivePictures, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SkyDrivePictures" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_StartMenu, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_StartMenu" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Startup, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Startup" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SyncManagerFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SyncManagerFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SyncResultsFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SyncResultsFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SyncSetupFolder, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SyncSetupFolder" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_System, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_System" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_SystemX86, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_SystemX86" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Templates, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Templates" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_UserPinned, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_UserPinned" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_UserProfiles, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_UserProfiles" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_UserProgramFiles, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_UserProgramFiles" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_UserProgramFilesCommon, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_UserProgramFilesCommon" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_UsersFiles, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_UsersFiles" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_UsersLibraries, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_UsersLibraries" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Videos, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Videos" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_VideosLibrary, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_VideosLibrary" << std::endl;
    return E_NOTIMPL;
  }

  if (memcmp(rfid, &FOLDERID_Windows, sizeof(KNOWNFOLDERID)) == 0) {
    std::cout << "SHGetKnownFolderPath: Unimplemented known folder ID: FOLDERID_Windows" << std::endl;
    return E_NOTIMPL;
  }

  return E_INVALIDARG;
}

