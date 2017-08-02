import React, {PureComponent} from 'react';
import {Link} from 'react-router';

class ChangeModeButtonAdvance extends PureComponent{

    render(){

        return(
            <div className="col-md-3">
                <Link to='/' className="btn btn-default btn-lg btn-block" role="button">일반설정</Link>
            </div>
        )
    }
}

export default ChangeModeButtonAdvance;
