#include "../../virtual/skinning/module.h"
#include "parse_functions.h"

namespace Utility
{

    /// Parse single armature
    bool ParseArmature(System::Buffer& buffer, Virtual::Armature* armature)
    {
        CHECK_START(buffer);
        while (1)
        {
            if (buffer.IsEnd())
            {
                out_error() << L"Can't parse object" << std::endl;
                return false;
            }

            System::string word = buffer.ReadWord();
            KeywordCode index;
            switch(index = Parse(word))
            {
            case WORD_CLOSE_BRACKET:
                armature->UpdateHierarchy();
                return true;
            case WORD_NAME:
            {
                System::string name;
                if (!ParseBlockedString(buffer, name))
                    return (out_error() << "Unable to parse armature name" << std::endl, false);
                armature->SetName(name);
                armature->SetStorageName(name);
            }
                break;
            case WORD_BONE:
            {
                std::unique_ptr<Virtual::Bone> bone(new Virtual::Bone);
                if (!ParseBone(buffer, bone.get()))
                    return (out_error() << "Unable to parse armature bone" << std::endl, false);
                Virtual::Bone* parent = armature->GetBoneByName(bone->GetParentName());
                if (parent)
                    parent->AddChild(bone.release());
                else
                    armature->AddRootBone(bone.release());
            }
                break;
            default:
                return (out_error() << L"Unknown keyword: " << word << std::endl, false);
            }
        }
        return false;
    }

    bool ParseArmatures(System::Buffer& buffer)
    {
        CHECK_START(buffer);
        while (1)
        {
            System::string word = buffer.ReadWord();
            KeywordCode code = Parse(word);
            switch(code)
            {
            case WORD_CLOSE_BRACKET:
                return true;
            case WORD_ARMATURE:
            {
                std::unique_ptr<Virtual::Armature> armature(new Virtual::Armature);
                ParseArmature(buffer, armature.get());
                Virtual::Armature::add(armature->GetStorageName(), armature.get());
                armature.release();
            }
                break;
            default:
                throw System::PunkInvalidArgumentException(L"Unexpected keyword " + word);
            }
        }
        return false;
    }
}
