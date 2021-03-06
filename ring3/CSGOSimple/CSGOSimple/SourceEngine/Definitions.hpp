#pragma once

#include <Windows.h>

namespace se
{
    typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);
    typedef void* (*InstantiateInterfaceFn)();

    typedef unsigned int VPANEL;
    typedef void(*pfnDemoCustomDataCallback)(unsigned char *pData, size_t iSize);

    template<typename FuncType>
    inline FuncType CallVFunction(void* ppClass, DWORD index)
    {
        PDWORD pVTable = *(PDWORD*)ppClass;
        DWORD dwAddress = pVTable[index];
        return (FuncType)(dwAddress);
    }

    enum class FontFeature
    {
        FONT_FEATURE_ANTIALIASED_FONTS = 1,
        FONT_FEATURE_DROPSHADOW_FONTS = 2,
        FONT_FEATURE_OUTLINE_FONTS = 6,
    };

    enum class FontDrawType
    {
        FONT_DRAW_DEFAULT = 0,
        FONT_DRAW_NONADDITIVE,
        FONT_DRAW_ADDITIVE,
        FONT_DRAW_TYPE_COUNT = 2,
    };

    enum class FontFlags
    {
        FONTFLAG_NONE,
        FONTFLAG_ITALIC = 0x001,
        FONTFLAG_UNDERLINE = 0x002,
        FONTFLAG_STRIKEOUT = 0x004,
        FONTFLAG_SYMBOL = 0x008,
        FONTFLAG_ANTIALIAS = 0x010,
        FONTFLAG_GAUSSIANBLUR = 0x020,
        FONTFLAG_ROTARY = 0x040,
        FONTFLAG_DROPSHADOW = 0x080,
        FONTFLAG_ADDITIVE = 0x100,
        FONTFLAG_OUTLINE = 0x200,
        FONTFLAG_CUSTOM = 0x400,
        FONTFLAG_BITMAP = 0x800,
    };

    enum class EntityFlags
    {
        FL_ONGROUND = (1 << 0),
        FL_DUCKING = (1 << 1),
        FL_WATERJUMP = (1 << 2),
        FL_ONTRAIN = (1 << 3),
        FL_INRAIN = (1 << 4),
        FL_FROZEN = (1 << 5),
        FL_ATCONTROLS = (1 << 6),
        FL_CLIENT = (1 << 7),
        FL_FAKECLIENT = (1 << 8)
    };

    enum class ClientFrameStage_t
    {
        FRAME_UNDEFINED = -1,
        FRAME_START,
        FRAME_NET_UPDATE_START,
        FRAME_NET_UPDATE_POSTDATAUPDATE_START,
        FRAME_NET_UPDATE_POSTDATAUPDATE_END,
        FRAME_NET_UPDATE_END,
        FRAME_RENDER_START,
        FRAME_RENDER_END
    };

    enum class LifeState
    {
        LIFE_ALIVE = 0,// alive
        LIFE_DYING = 1, // playing death animation or still falling off of a ledge waiting to hit ground
        LIFE_DEAD = 2 // dead. lying still.
    };

    enum EItemDefinitionIndex
    {
        weapon_deagle = 1,
        weapon_elite = 2,
        weapon_fiveseven = 3,
        weapon_glock = 4,
        weapon_ak47 = 7,
        weapon_aug = 8,
        weapon_awp = 9,
        weapon_famas = 10,
        weapon_g3sg1 = 11,
        weapon_galilar = 13,
        weapon_m249 = 14,
        weapon_m4a1 = 16,
        weapon_mac10 = 17,
        weapon_p90 = 19,
        weapon_ump = 24,
        weapon_xm1014 = 25,
        weapon_bizon = 26,
        weapon_mag7 = 27,
        weapon_negev = 28,
        weapon_sawedoff = 29,
        weapon_tec9 = 30,
        weapon_taser = 31,
        weapon_hkp2000 = 32,
        weapon_mp7 = 33,
        weapon_mp9 = 34,
        weapon_nova = 35,
        weapon_p250 = 36,
        weapon_scar20 = 38,
        weapon_sg556 = 39,
        weapon_ssg08 = 40,
        weapon_knife = 42,
        weapon_flashbang = 43,
        weapon_hegrenade = 44,
        weapon_smokegrenade = 45,
        weapon_molotov = 46,
        weapon_decoy = 47,
        weapon_incgrenade = 48,
        weapon_c4 = 49,
        weapon_knife_t = 59,
        weapon_m4a1_silencer = 60,
        weapon_usp_silencer = 61,
        weapon_cz75a = 63,
        weapon_revolver = 64,
        weapon_bayonet = 500,
        weapon_knife_flip = 505,
        weapon_knife_gut = 506,
        weapon_knife_karambit = 507,
        weapon_knife_m9_bayonet = 508,
        weapon_knife_tactical = 509,
        weapon_knife_falchion = 512,
        weapon_knife_survival_bowie = 514,
        weapon_knife_butterfly = 515,
        weapon_knife_push = 516
    };

    enum EClassIds
    {
		CAI_BaseNPC = 0,
		CAK47,
		CBaseAnimating,
		CBaseAnimatingOverlay,
		CBaseAttributableItem,
		CBaseButton,
		CBaseCombatCharacter,
		CBaseCombatWeapon,
		CBaseCSGrenade,
		CBaseCSGrenadeProjectile,
		CBaseDoor,
		CBaseEntity,
		CBaseFlex,
		CBaseGrenade,
		CBaseParticleEntity,
		CBasePlayer,
		CBasePropDoor,
		CBaseTeamObjectiveResource,
		CBaseTempEntity,
		CBaseToggle,
		CBaseTrigger,
		CBaseViewModel,
		CBaseVPhysicsTrigger,
		CBaseWeaponWorldModel,
		CBeam,
		CBeamSpotlight,
		CBoneFollower,
		CBreakableProp,
		CBreakableSurface,
		CC4,
		CCascadeLight,
		CChicken,
		CColorCorrection,
		CColorCorrectionVolume,
		CCSGameRulesProxy,
		CCSPlayer,
		CCSPlayerResource,
		CCSRagdoll,
		CCSTeam,
		CDEagle,
		CDecoyGrenade,
		CDecoyProjectile,
		CDynamicLight,
		CDynamicProp,
		CEconEntity,
		CEconWearable,
		CEmbers,
		CEntityDissolve,
		CEntityFlame,
		CEntityFreezing,
		CEntityParticleTrail,
		CEnvAmbientLight,
		CEnvDetailController,
		CEnvDOFController,
		CEnvParticleScript,
		CEnvProjectedTexture,
		CEnvQuadraticBeam,
		CEnvScreenEffect,
		CEnvScreenOverlay,
		CEnvTonemapController,
		CEnvWind,
		CFEPlayerDecal,
		CFireCrackerBlast,
		CFireSmoke,
		CFireTrail,
		CFish,
		CFlashbang,
		CFogController,
		CFootstepControl,
		CFunc_Dust,
		CFunc_LOD,
		CFuncAreaPortalWindow,
		CFuncBrush,
		CFuncConveyor,
		CFuncLadder,
		CFuncMonitor,
		CFuncMoveLinear,
		CFuncOccluder,
		CFuncReflectiveGlass,
		CFuncRotating,
		CFuncSmokeVolume,
		CFuncTrackTrain,
		CGameRulesProxy,
		CHandleTest,
		CHEGrenade,
		CHostage,
		CHostageCarriableProp,
		CIncendiaryGrenade,
		CInferno,
		CInfoLadderDismount,
		CInfoOverlayAccessor,
		CItem_Healthshot,
		CKnife,
		CKnifeGG,
		CLightGlow,
		CMaterialModifyControl,
		CMolotovGrenade,
		CMolotovProjectile,
		CMovieDisplay,
		CParticleFire,
		CParticlePerformanceMonitor,
		CParticleSystem,
		CPhysBox,
		CPhysBoxMultiplayer,
		CPhysicsProp,
		CPhysicsPropMultiplayer,
		CPhysMagnet,
		CPlantedC4,
		CPlasma,
		CPlayerResource,
		CPointCamera,
		CPointCommentaryNode,
		CPoseController,
		CPostProcessController,
		CPrecipitation,
		CPrecipitationBlocker,
		CPredictedViewModel,
		CProp_Hallucination,
		CPropDoorRotating,
		CPropJeep,
		CPropVehicleDriveable,
		CRagdollManager,
		CRagdollProp,
		CRagdollPropAttached,
		CRopeKeyframe,
		CSCAR17,
		CSceneEntity,
		CSensorGrenade,
		CSensorGrenadeProjectile,
		CShadowControl,
		CSlideshowDisplay,
		CSmokeGrenade,
		CSmokeGrenadeProjectile,
		CSmokeStack,
		CSpatialEntity,
		CSpotlightEnd,
		CSprite,
		CSpriteOriented,
		CSpriteTrail,
		CStatueProp,
		CSteamJet,
		CSun,
		CSunlightShadowControl,
		CTeam,
		CTeamplayRoundBasedRulesProxy,
		CTEArmorRicochet,
		CTEBaseBeam,
		CTEBeamEntPoint,
		CTEBeamEnts,
		CTEBeamFollow,
		CTEBeamLaser,
		CTEBeamPoints,
		CTEBeamRing,
		CTEBeamRingPoint,
		CTEBeamSpline,
		CTEBloodSprite,
		CTEBloodStream,
		CTEBreakModel,
		CTEBSPDecal,
		CTEBubbles,
		CTEBubbleTrail,
		CTEClientProjectile,
		CTEDecal,
		CTEDust,
		CTEDynamicLight,
		CTEEffectDispatch,
		CTEEnergySplash,
		CTEExplosion,
		CTEFireBullets,
		CTEFizz,
		CTEFootprintDecal,
		CTEFoundryHelpers,
		CTEGaussExplosion,
		CTEGlowSprite,
		CTEImpact,
		CTEKillPlayerAttachments,
		CTELargeFunnel,
		CTEMetalSparks,
		CTEMuzzleFlash,
		CTEParticleSystem,
		CTEPhysicsProp,
		CTEPlantBomb,
		CTEPlayerAnimEvent,
		CTEPlayerDecal,
		CTEProjectedDecal,
		CTERadioIcon,
		CTEShatterSurface,
		CTEShowLine,
		CTesla,
		CTESmoke,
		CTESparks,
		CTESprite,
		CTESpriteSpray,
		CTest_ProxyToggle_Networkable,
		CTestTraceline,
		CTEWorldDecal,
		CTriggerPlayerMovement,
		CTriggerSoundOperator,
		CVGuiScreen,
		CVoteController,
		CWaterBullet,
		CWaterLODControl,
		CWeaponAug,
		CWeaponAWP,
		CWeaponBaseItem,
		CWeaponBizon,
		CWeaponCSBase,
		CWeaponCSBaseGun,
		CWeaponCycler,
		CWeaponElite,
		CWeaponFamas,
		CWeaponFiveSeven,
		CWeaponG3SG1,
		CWeaponGalil,
		CWeaponGalilAR,
		CWeaponGlock,
		CWeaponHKP2000,
		CWeaponM249,
		CWeaponM3,
		CWeaponM4A1,
		CWeaponMAC10,
		CWeaponMag7,
		CWeaponMP5Navy,
		CWeaponMP7,
		CWeaponMP9,
		CWeaponNegev,
		CWeaponNOVA,
		CWeaponP228,
		CWeaponP250,
		CWeaponP90,
		CWeaponSawedoff,
		CWeaponSCAR20,
		CWeaponScout,
		CWeaponSG550,
		CWeaponSG552,
		CWeaponSG556,
		CWeaponSSG08,
		CWeaponTaser,
		CWeaponTec9,
		CWeaponTMP,
		CWeaponUMP45,
		CWeaponUSP,
		CWeaponXM1014,
		CWorld,
		DustTrail,
		MovieExplosion,
		ParticleSmokeGrenade,
		RocketTrail,
		SmokeTrail,
		SporeExplosion,
		SporeTrail,

    };

    enum ECSPlayerBones
    {
        pelvis = 0,
        spine_0,
        spine_1,
        spine_2,
        spine_3,
        neck_0,
        head_0,
        clavicle_L,
        arm_upper_L,
        arm_lower_L,
        hand_L
    };
}
