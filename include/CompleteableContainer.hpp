//
// Created by George Ford on 12/17/23.
//

#ifndef COMPLETEABLECONTAINER_HPP
#define COMPLETEABLECONTAINER_HPP

#include "Completable.hpp"
#include "GtdBaseContainer.hpp"

namespace gtd {
using pCompletable_t = std::unique_ptr<Completable>;

class CompleteableContainer : public GtdContainer
{
protected:
    std::vector<pCompletable_t> _gtdItems;

public:
    // Type definitions
    using value_type = std::vector<pCompletable_t>::value_type;
    using iterator = std::vector<pCompletable_t>::iterator;
    using const_iterator = std::vector<pCompletable_t>::const_iterator;
    using size_type = std::vector<pCompletable_t>::size_type;
    using difference_type = std::vector<pCompletable_t>::difference_type;

    explicit
    CompleteableContainer( USMgr& );
    CompleteableContainer( const CompleteableContainer& );
    ~CompleteableContainer() override;

    CompleteableContainer&
    operator=( const CompleteableContainer& );

    [[nodiscard]] const std::string&
    tableName() const override = 0;

    [[nodiscard]]
    auto
    begin() override;

    [[nodiscard]]
    auto
    cbegin() const override;

    [[nodiscard]]
    auto
    end() override;

    [[nodiscard]]
    auto
    cend() const override;

    virtual void
    push_back( pCompletable_t );

    virtual void
    push_back( Completable* );
    [[nodiscard]] std::ranges<pCompletable_t>
    getWithContextId( unique_id_t ) const;

    [[nodiscard]] std::ranges<pCompletable_t>
    getAfterDeferredInclusive( time_point_t ) const;

    [[nodiscard]] std::ranges<pCompletable_t>
    getBeforeDeferredInclusive( time_point_t ) const;

    [[nodiscard]] std::ranges<pCompletable_t>
    getAfterDueInclusive( time_point_t ) const;

    [[nodiscard]] std::ranges<pCompletable_t>
    getFlagged() const;
};
} // namespace gtd

#endif //COMPLETEABLECONTAINER_HPP
