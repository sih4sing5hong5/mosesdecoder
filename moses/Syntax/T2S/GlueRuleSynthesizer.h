#pragma once

#include "moses/Phrase.h"
#include "moses/TargetPhrase.h"

#include "InputTree.h"
#include "RuleTrie.h"
#include "RuleTrieCreator.h"

namespace Moses
{
namespace Syntax
{
namespace T2S
{

class GlueRuleSynthesizer : public RuleTrieCreator
{
public:
  GlueRuleSynthesizer(RuleTrie &trie) : m_ruleTrie(trie) {}

  // Synthesize the minimal, montone rule that can be applied to the given node
  // and add it to the rule trie.
  void SynthesizeRule(const InputTree::Node &);

private:
  Phrase *SynthesizeSourcePhrase(const InputTree::Node &);
  TargetPhrase *SynthesizeTargetPhrase(const InputTree::Node &, const Phrase &);

  RuleTrie &m_ruleTrie;
};

}  // T2S
}  // Syntax
}  // Moses
