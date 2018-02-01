/* Copyright (c) 2013-2017, EPFL/Blue Brain Project
 *                          Daniel Nachbaur <daniel.nachbaur@epfl.ch>
 *
 * This file is part of Brion <https://github.com/BlueBrain/Brion>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BRION_TYPES
#define BRION_TYPES

#include "enums.h"
#include "exceptions.h"

#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#pragma warning(push)
#pragma warning(disable : 4996)
#include <vmmlib/types.hpp>
#pragma warning(pop)

#ifdef __GNUC__
#define BRION_UNUSED __attribute__((unused))
#else
#define BRION_UNUSED
#endif

// TODO: bcoste fix me
#define LBTHROW throw
#define LBERROR std::cerr
#define LBWARN std::cerr

/** @namespace minimorph Blue Brain File IO classes */
namespace minimorph
{
typedef std::string URI;

using namespace enums;
class Morphology;
class MorphologyInitData;

using vmml::Vector2i;
using vmml::Vector3f;
using vmml::Vector4f;
using vmml::Vector3d;
using vmml::Vector4d;
using vmml::Matrix4f;

typedef std::vector<size_t> size_ts;
typedef std::vector<int32_t> int32_ts;
typedef std::vector<uint16_t> uint16_ts;
typedef std::vector<uint32_t> uint32_ts;
typedef std::vector<uint64_t> uint64_ts;
typedef std::vector<float> floats;
typedef std::vector<double> doubles;
typedef std::vector<Vector2i> Vector2is;
typedef std::vector<Vector3f> Vector3fs;
typedef std::vector<Vector4f> Vector4fs;
typedef std::vector<Vector3d> Vector3ds;
typedef std::vector<Vector4d> Vector4ds;
typedef std::vector<SectionType> SectionTypes;

typedef std::shared_ptr<int32_ts> int32_tsPtr;
typedef std::shared_ptr<uint16_ts> uint16_tsPtr;
typedef std::shared_ptr<uint32_ts> uint32_tsPtr;
typedef std::shared_ptr<floats> floatsPtr;
typedef std::shared_ptr<doubles> doublesPtr;
typedef std::shared_ptr<Vector3fs> Vector3fsPtr;
typedef std::shared_ptr<Vector3ds> Vector3dsPtr;
typedef std::shared_ptr<Vector4ds> Vector4dsPtr;

using MorphologyPtr = std::shared_ptr<Morphology>;
using ConstMorphologyPtr = std::shared_ptr<const Morphology>;

typedef std::vector<std::string> Strings;

} // namespace minimorph


namespace morphio
{
/** High-level interface to neuron morphologies. */
class Morphology;
class Section;
class Soma;

enum class SectionType
{
    soma = minimorph::enums::SECTION_SOMA,
        axon = minimorph::enums::SECTION_AXON,
        dendrite = minimorph::enums::SECTION_DENDRITE,
        basalDendrite = minimorph::enums::SECTION_BASAL_DENDRITE,
        apicalDendrite = minimorph::enums::SECTION_APICAL_DENDRITE,
        undefined = minimorph::enums::SECTION_UNDEFINED,
        all = minimorph::enums::SECTION_ALL
        };

typedef std::shared_ptr<Morphology> MorphologyPtr;

typedef std::vector<MorphologyPtr> Morphologies;
typedef std::vector<Section> Sections;
typedef std::vector<SectionType> SectionTypes;


using vmml::Matrix4f;
using vmml::Quaternionf;
using vmml::Vector2i;
using vmml::Vector3f;
using vmml::Vector4f;

using minimorph::Strings;
using minimorph::URI;
using minimorph::Vector2is;
using minimorph::Vector3fs;
using minimorph::Vector4fs;
using minimorph::floats;
using minimorph::uint32_ts;
using minimorph::size_ts;

// Brion exceptions
using minimorph::RawDataError;
using minimorph::SomaError;
using minimorph::IDSequenceError;
using minimorph::MultipleTrees;
using minimorph::MissingParentError;

typedef std::vector<Matrix4f> Matrix4fs;
typedef std::vector<Quaternionf> Quaternionfs;


/**
 * The GID of a synapse is the a tuple of two numbers:
 * - The GID of the post-synaptic cell.
 * - The index of the synapse in the array of afferent contacts
 *   of the post-synaptic cell before pruning/filtering.
 * GIDs are invariant regardless of how the structural touches are
 * converted into functional synapses during circuit building.
 */
typedef std::pair<uint32_t, size_t> SynapseGID;


} // namespace morphio

//TODO: compile
#if 0
// if you have a type T in namespace N, the operator << for T needs to be in
// namespace N too
namespace boost
{
template <typename T>
inline std::ostream& operator<<(std::ostream& os,
                                const boost::multi_array<T, 2>& data)
{
    for (size_t i = 0; i < data.shape()[0]; ++i)
    {
        for (size_t j = 0; j < data.shape()[1]; ++j)
            os << data[i][j] << " ";
        os << std::endl;
    }
    return os;
}
}

namespace std
{
template <class T, class U>
inline std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& pair)
{
    return os << "[ " << pair.first << ", " << pair.second << " ]";
}
}
#endif

#endif
